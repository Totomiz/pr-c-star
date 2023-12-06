//
// Created by Lenovot on 2023/11/30.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // 创建套接字
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 设置套接字选项
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // 绑定套接字到指定端口
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }


    while (1) {
        // 监听连接
        if (listen(server_fd, 3) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
        }else{
            printf("listen conn -> %i",server_fd);
        }

        // 接受连接
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }else{
            printf("accept conn -> %i",server_fd);
        }

        while (1) {
            // 读取数据
            if (read(new_socket, buffer, sizeof(buffer)) == 0) {
                printf("client disconnect\n");
                break;
            }
            printf("Client: %s\n", buffer);
            send(new_socket, hello, strlen(hello), 0);
            printf("Hello message sent\n");

            // 清空缓冲区
            memset(buffer, 0, sizeof(buffer));
        }

        // 关闭与客户端的连接
        close(new_socket);
    }


//    while (1){
//        // 监听连接
//        if (listen(server_fd, 3) < 0) {
//            perror("listen");
//            exit(EXIT_FAILURE);
//        }
//
//        // 接受连接
//        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
//            perror("accept");
//            exit(EXIT_FAILURE);
//        }
//
//        // 读取数据
//        if (read(new_socket, buffer, sizeof(buffer)) == 0) {
//            printf("server disconnect\n");
//            break;
//        }
//        printf("Client: %s\n", buffer);
//        send(new_socket, hello, strlen(hello), 0);
//        printf("Hello message sent\n");
//
//    }

    return 0;
}