//
// Created by Lenovot on 2023/12/6.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8888
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_message(int sockfd, const char *message) {
    int n = write(sockfd, message, strlen(message));
    if (n < 0)
        error("Error writing to socket");
}

void receive_message(int sockfd, char *buffer) {
    int n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0)
        error("Error reading from socket");
    buffer[n] = '\0';
}



int main() {
    int sockfd, newsockfd, pid;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    // 创建套接字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket");

    // 设置服务器地址
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // 绑定套接字到指定端口
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("Error on binding");

    // 监听连接
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // 接受客户端连接
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("Error on accept");

    pid = fork();
    if (pid < 0)
        error("Error on fork");

    if (pid == 0) {  // 子进程用于发送消息
        close(sockfd);

        while (1) {
            printf("Please enter the message: ");
            fgets(buffer, BUFFER_SIZE - 1, stdin);

            send_message(newsockfd, buffer);
            if (strncmp(buffer, "exit", 4) == 0)
                break;
        }
    } else {  // 父进程用于接收消息
        close(newsockfd);

        while (1) {
            receive_message(sockfd, buffer);
            printf("Received message: %s", buffer);

            if (strncmp(buffer, "exit", 4) == 0)
                break;
        }
    }

    close(sockfd);
    return 0;
}
