//
// Created by Lenovot on 2023/12/6.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <getopt.h>
#include <arpa/inet.h>

#define TAG "ChatBox"
#define LOGD(...) printf(__VA_ARGS__); printf("\n")


int sendMessage(const char* message, const char* ip, int port) {
    // 进行发送消息的处理
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd == -1) {
        LOGD("create serverFd failed!");
        return -1;
    }

    // 设置服务器地址和端口
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);

    if (connect(serverFd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        LOGD("conn serverFd failed!");
        close(serverFd);
        return -1;
    }

    // 发送消息
    ssize_t ret = send(serverFd, message, strlen(message), 0);

    // 关闭socket
    close(serverFd);

    // 判断是否发送成功
    if (ret == -1) {
        return -1;
    } else {
        LOGD("send success:%s ",message);
        return 0;
    }
}
void handleReceivedMessage(const char* message) {
    // 在这里处理接收到的消息
    printf("Received message: %s\n", message);
}

int receiveMessage(int clientFd) {
    // 接收消息
    char buffer[1024];
    ssize_t bytesRead = recv(clientFd, buffer, sizeof(buffer) - 1, 0);
    if (bytesRead <= 0) {
        return -1;
    }

    buffer[bytesRead] = '\0';

    // 处理接收到的消息
    handleReceivedMessage(buffer);

    return 0;
}


int startTcpServer(int port) {
    // 创建socket
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd == -1) {
        LOGD("create serverFd failed!");
        return -1;
    }

    // 绑定监听地址
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    if (bind(serverFd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        LOGD("bind failed");
        close(serverFd);
        return -1;
    }

    // 获取本地地址和端口号
    struct sockaddr_in localaddr;
    socklen_t addr_len = sizeof(localaddr);
    if (getsockname(serverFd, (struct sockaddr *)&localaddr, &addr_len) == -1) {
        LOGD("getsockname error!");
    } else {
        char ip[20] = {0};
        inet_ntop(AF_INET, (void*)&localaddr.sin_addr.s_addr, ip, sizeof(ip));
        int port = ntohs(localaddr.sin_port);
        LOGD("server listening on %s:%d...\n", ip, port);
    }

    // 开始监听
    if (listen(serverFd, 10) == -1) {
        LOGD("listen serverFd failed!");
        close(serverFd);
        return -1;
    }

    // 循环接收客户端连接
    while (1) {
        struct sockaddr_in clientAddr;
        memset(&clientAddr, 0, sizeof(clientAddr));
        socklen_t len = sizeof(clientAddr);
        int clientFd = accept(serverFd, (struct sockaddr *) &clientAddr, &len);
        if (clientFd == -1) {
            continue;
        }

        char buf[1024] = {0};
        ssize_t ret = recv(clientFd, buf, sizeof(buf), 0);

        if (ret == -1) {
            close(clientFd);
            continue;
        }

        handleReceivedMessage(buf);
        close(clientFd);
    }

    // 关闭服务器socket
    close(serverFd);
    return 0;
}


int main(int argc, char *argv[]) {
    int startPort = -1;

    // 解析命令行参数
    int opt;
    char *ip = NULL;
    int port = -1;
    char *message = NULL;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s -p <port> [-e <IPV4>:<PORT>] [-m <message>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    while ((opt = getopt(argc, argv, "p:e:m:")) != -1) {
        switch (opt) {
            case 'p':
                startPort = atoi(optarg);
                break;
            case 'e':
            {
                char *p = strchr(optarg, ':');
                if (p == NULL) {
                    fprintf(stderr, "Invalid parameter: %s\n", optarg);
                    exit(EXIT_FAILURE);
                }
                ip = strndup(optarg, p - optarg);
                port = atoi(p + 1);
            }
                break;
            case 'm':
                message = strdup(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s -p <port> [-e <IPV4>:<PORT>] [-m <message>]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }


    // 启动服务器
    if (startPort >= 0) {
        printf("Starting server on port %d\n", startPort);
        startTcpServer(startPort);
    }

    // 发送消息
    if (ip != NULL && message != NULL && port >= 0) {
        printf("Sending message '%s' to %s:%d\n", message, ip, port);
        sendMessage(message, ip, port);
    }

    free(ip);
    free(message);

    return 0;
}