//
// Created by Lenovot on 2023/11/30.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080


int main2(int argc, char const *argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};

    // 创建套接字
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 将 IPv4 地址从文本转换为二进制
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // 连接到服务器
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // 发送消息
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    read(sock, buffer, 1024);
    printf("Server: %s\n", buffer);

    return 0;
}


int main(int argc, char *argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char message[1024] = {0};

    // 创建套接字
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n socket create error;");
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    // 将 IPv4 地址从文本转换为二进制 1 success 0和-1都有问题
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    while (1) {
        printf("Enter  message:");
        fgets(message, sizeof(message), stdin);
        // 发送
        send(sock, message, strlen(message), 0);

        // 清空消息缓冲

        memset(message, 0, sizeof(message));

        if (read(sock, message, sizeof(message)) == 0) {
            printf("server disconnect\n");
            break;
        }
        printf("Server: %s", message);
    }

    close(sock);
    return 0;

}

//写一个程序chatbox , 运行时候拥有两个子进程p1,p2,当在AB两个主机上运行的时候，A主机中的p1进程

//int main(int argc, char const *argv[]) {
//    int sock = 0;
//    struct sockaddr_in serv_addr;
//    char message[1024] = {0};
//
//    // 创建套接字
//    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
//        printf("\n Socket creation error \n");
//        return -1;
//    }
//
//    serv_addr.sin_family = AF_INET;
//    serv_addr.sin_port = htons(PORT);
//
//    // 将 IPv4 地址从文本转换为二进制
//    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
//        printf("\nInvalid address/ Address not supported \n");
//        return -1;
//    }
//
//    // 连接到服务器
//    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
//        printf("\nConnection Failed \n");
//        return -1;
//    }
//
//    // 发送和接收消息
//    while(1){
//        printf("Enter message: ");
//        fgets(message, sizeof(message), stdin);
//
//        // 发送消息
//        send(sock, message, strlen(message), 0);
//
//        // 清空消息缓冲区
//        memset(message, 0, sizeof(message));
//
//        // 接收消息
//        if(read(sock, message, sizeof(message)) == 0){
//            printf("Server disconnected.\n");
//            break;
//        }
//
//        printf("Server: %s", message);
//    }
//
//    // 关闭套接字
//    close(sock);
//
//    return 0;
//}

