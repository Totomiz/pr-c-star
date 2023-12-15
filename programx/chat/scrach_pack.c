//
// Created by Lenovot on 2023/12/13.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <net/if.h>
#include <sys/ioctl.h>

int main() {
    int sock_fd;
    struct sockaddr_in sa;
    struct ifreq ifr;
    unsigned char buffer[ETH_FRAME_LEN];

    // 创建原始套接字
    sock_fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock_fd == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    // 设置网络接口和端口号
    memset(&ifr, 0, sizeof(struct ifreq));
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);  // 替换为实际的网络接口名
    if (ioctl(sock_fd, SIOCGIFINDEX, &ifr) == -1) {
        perror("Failed to get interface index");
        close(sock_fd);
        exit(1);
    }

    memset(&sa, 0, sizeof(struct sockaddr_ll));
    sa.sin_family = AF_PACKET;
    sa.sll_protocol = htons(ETH_P_ALL);
    sa.sll_ifindex = ifr.ifr_ifindex;

    if (bind(sock_fd, (struct sockaddr *)&sa, sizeof(struct sockaddr_ll)) == -1) {
        perror("Failed to bind to interface");
        close(sock_fd);
        exit(1);
    }

    // 循环接收数据
    while (1) {
        ssize_t length = recvfrom(sock_fd, buffer, ETH_FRAME_LEN, 0, NULL, NULL);
        if (length == -1) {
            perror("Failed to receive data");
            close(sock_fd);
            exit(1);
        }

        // 在这里处理接收到的数据链路层数据帧
        // 可以根据需要进行进一步解析和处理

        // 示例：打印数据帧的前 14 字节（目标 MAC 地址、源 MAC 地址、以太网类型）
        printf("Received frame: ");
        for (int i = 0; i < length && i < 14; i++) {
            printf("%02X ", buffer[i]);
        }
        printf("\n");
    }

    close(sock_fd);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <net/if.h>

int main() {
    int sock_fd;
    struct sockaddr_ll sa;
    struct ifreq ifr;
    unsigned char buffer[ETH_FRAME_LEN];

    // 创建原始套接字
    sock_fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock_fd == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    // 设置网络接口和端口号
    memset(&ifr, 0, sizeof(struct ifreq));
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);  // 替换为实际的网络接口名
    if (ioctl(sock_fd, SIOCGIFINDEX, &ifr) == -1) {
        perror("Failed to get interface index");
        close(sock_fd);
        exit(1);
    }

    memset(&sa, 0, sizeof(struct sockaddr_ll));
    sa.sll_family = AF_PACKET;
    sa.sll_protocol = htons(ETH_P_ALL);
    sa.sll_ifindex = ifr.ifr_ifindex;

    if (bind(sock_fd, (struct sockaddr *)&sa, sizeof(struct sockaddr_ll)) == -1) {
        perror("Failed to bind to interface");
        close(sock_fd);
        exit(1);
    }

    // 循环接收数据
    while (1) {
        ssize_t length = recvfrom(sock_fd, buffer, ETH_FRAME_LEN, 0, NULL, NULL);
        if (length == -1) {
            perror("Failed to receive data");
            close(sock_fd);
            exit(1);
        }

        // 在这里处理接收到的数据链路层数据帧
        // 可以根据需要进行进一步解析和处理

        // 示例：打印数据帧的前 14 字节（目标 MAC 地址、源 MAC 地址、以太网类型）
        printf("Received frame: ");
        for (int i = 0; i < length && i < 14; i++) {
            printf("%02X ", buffer[i]);
        }
        printf("\n");
    }

    close(sock_fd);
    return 0;
}