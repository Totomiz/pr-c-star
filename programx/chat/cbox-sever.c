//
// Created by Lenovot on 2023/12/8.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <ifaddrs.h>

#define LOGD(...) do{ \
                        printf(__VA_ARGS__);  \
                        printf("\n"); \
                    } while(0)
#define PORT 8888
#define TCP_PORT 8888

int hasConnectToTcp = 0;

int udpServerFd = -1;
int tcpServerFd = -1;
struct sockaddr_in udp_client_addr;
struct sockaddr_in udp_server_addr;


void *receive_udp_messages(void *arg) {
    int sockfd = *((int *) arg);
    socklen_t addr_len = sizeof(udp_client_addr);
    char buffer[1024];
    while (1) {
        // 接收来自主机B的数据
        memset(buffer, 0, sizeof(buffer));
        recvfrom(sockfd, (char *) buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr *) &udp_client_addr, &addr_len);
        printf("Received data from Host B at %s:%d\n", inet_ntoa(udp_client_addr.sin_addr),
               ntohs(udp_client_addr.sin_port));
        printf("Data: %s\n", buffer);

    }
}

/**
 * 连接tcp服务
 * @param port
 */
void connTcpSelf(int port) {
    int tcpClientFd = socket(PF_INET, SOCK_STREAM, 0);
    if (tcpClientFd == -1) {
        LOGD("Conn tcp fd failed!");
    }
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    bzero(&addr, addr_len);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl('127.0.0.1');
    addr.sin_port = port;
    errno = 0;
    if (connect(tcpClientFd, (struct sockaddr *) &addr, addr_len) == -1) {
        LOGD("conn tcp failed %s", strerror(errno));
        close(tcpClientFd);
        return;
    }else{
        LOGD("conn tcp success");
    }

    char buffer[1024];
    // send
    while (1) {
        // 向主机B发送数据
        printf("Enter tcp message: \n");
        fgets(buffer, sizeof(buffer), stdin);
        send(tcpClientFd, buffer, sizeof(buffer), 0);
        printf("Message sent.\n");
    }

}


/**
 * 创建tcp server
 * @param port
 */
void createTcpServer(int port) {

    tcpServerFd = socket(AF_INET, SOCK_STREAM, 0);
    if (tcpServerFd == -1) {
        LOGD("Create tcp fd failed!");
    }
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    memset(&addr, 0, addr_len);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);
    if (bind(tcpServerFd, (const struct sockaddr *) &addr, addr_len) == -1) {
        LOGD("bind tcp fd failed");
        close(tcpServerFd);
        return;
    }

    // 获取本地地址和端口号
    struct sockaddr_in localaddr;
    // 开始监听
    errno = 0;
    if (listen(tcpServerFd, 10) == -1) {
        LOGD("listen serverFd failed! %s", strerror(errno));
        close(tcpServerFd);
        return;
    }

    if (getsockname(tcpServerFd, (struct sockaddr *) &localaddr, &addr_len) == -1) {
        LOGD("getsockname error!");
    } else {
        char ip[20] = {0};
        inet_ntop(AF_INET, (void *) &localaddr.sin_addr.s_addr, ip, sizeof(ip));
        int realPort = ntohs(localaddr.sin_port);
        LOGD("server listening on %s:%d...\n", ip, realPort);
    }

    while (1) {

        struct sockaddr_in clientAddr;
        memset(&clientAddr, 0, sizeof(clientAddr));
        socklen_t len = sizeof(clientAddr);

        errno = 0;
        int clientFd = accept(tcpServerFd, (struct sockaddr *) &clientAddr, &len);
        LOGD("Inet ADDR LEN %u", len);
        if (clientFd == -1) {
            LOGD("accept failed! %s", strerror(errno));
            continue;
        }

        //打印连接的端口
        char clientIp[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(clientAddr.sin_addr), clientIp, INET_ADDRSTRLEN);
        int clientPort = ntohs(clientAddr.sin_port);
        LOGD("Client IP address: %s, Client Port: %d\n", clientIp, clientPort);

        char buf[1024] = {0};
        ssize_t ret = recv(clientFd, buf, sizeof(buf), 0);

        if (ret == -1) {
            close(clientFd);
            continue;
        }
//        handleReceivedMessage(buf);
//        close(clientFd);
    }

    // 关闭服务器socket
    close(tcpServerFd);
}


void *thread_func_tcp(void *arg) {
    int tcpPort = *((int *) arg);
    createTcpServer(tcpPort);
    return NULL;
}

void *thread_func_conn_tcp(void *arg) {
    sleep(1);
    int connPort = *((int *) arg);
    connTcpSelf(connPort);
    return NULL;
}

void print_router_ip() {
    struct ifaddrs *ifaddr, *ifa;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;

        if (ifa->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *sa = (struct sockaddr_in *) ifa->ifa_addr;
            printf("Router IP: %s\n", inet_ntoa(sa->sin_addr));
            break;
        }
    }

    freeifaddrs(ifaddr);
}


int main() {

    // 创建UDP socket
    if ((udpServerFd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 设置服务器地址信息
    bzero(&udp_server_addr, sizeof(udp_server_addr));
    memset(&udp_server_addr, 0, sizeof(udp_server_addr));
    udp_server_addr.sin_family = AF_INET;
    udp_server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    udp_server_addr.sin_port = htons(PORT);

    // 绑定服务器地址到socket
    if (bind(udpServerFd, (const struct sockaddr *) &udp_server_addr, sizeof(udp_server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    pthread_t receive_thread;
    pthread_create(&receive_thread, NULL, receive_udp_messages, &udpServerFd);
    pthread_t local_tcp_server_thread;
    int tcp_port = TCP_PORT;
    pthread_create(&local_tcp_server_thread, NULL, thread_func_tcp, &tcp_port);

    pthread_t local_tcp_conn_thread;
    pthread_create(&local_tcp_conn_thread, NULL, thread_func_conn_tcp, &tcp_port);

    print_router_ip();

    char buffer[1024];
    while (1) {
        // 向主机B发送数据
        printf("Enter message to send to Host B: \n");
        fgets(buffer, sizeof(buffer), stdin);
        sendto(udpServerFd, buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *) &udp_client_addr,
               sizeof
                       (udp_client_addr));
        printf("Message sent.\n");
    }
    pthread_cancel(receive_thread);
    pthread_cancel(local_tcp_server_thread);
    close(udpServerFd);
    return 0;
}