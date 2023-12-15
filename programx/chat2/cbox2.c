//
// Created by Lenovot on 2023/12/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 54549

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char message[1024];

    // 创建套接字
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 设置服务器地址信息
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // 连接服务器
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }
    while (1){
        // 从标准输入读取消息，并发送给服务器
        printf("Enter a message: ");
        fgets(message, sizeof(message), stdin);
        send(sockfd, message, strlen(message), 0);

    }


    // 关闭套接字
//        close(sockfd);
    return 0;
}