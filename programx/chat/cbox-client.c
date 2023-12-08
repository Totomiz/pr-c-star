//
// Created by Lenovot on 2023/12/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8888
#define IP "127.0.0.1"

void* receive_udp_messages(void* arg) {
    int sockfd = *((int*)arg);
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);

    char buffer[1024];
    while (1) {
        // 接收来自主机A的数据
        memset(buffer, 0, sizeof(buffer));
        recvfrom(sockfd, (char *)buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr *)&server_addr, &addr_len);
        printf("Received data from Host A: %s\n", buffer);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // 创建UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 设置服务器地址信息
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, IP, &(server_addr.sin_addr)) <= 0) { // 请替换为主机A的IP地址
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    pthread_t receive_thread;
    pthread_create(&receive_thread, NULL, receive_udp_messages, &sockfd);

    char buffer[1024];
    while (1) {
        // 向主机A发送数据
        printf("Sent to A: ");
        fgets(buffer, sizeof(buffer), stdin);
        sendto(sockfd, buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&server_addr, sizeof(server_addr));
        printf("Message sent.\n");
    }

    close(sockfd);
    return 0;
}