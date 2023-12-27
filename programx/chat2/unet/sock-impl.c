//
// Created by Lenovot on 2023/12/18.
//
#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/wait.h>

#include <netinet/in.h>

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ifaddrs.h>
#include "sock.h"


#define BACKLOG 5
#ifndef SLEEP
#define SLEEP   5
#endif
#define LOGD(...) do{ \
                        printf(__VA_ARGS__);  \
                        printf("\n"); \
                    } while(0)

#define LOGE(...) do{ \
                        fprintf(stderr,__VA_ARGS__); \
                        printf(": %s\n",strerror(errno)); \
                    } while(0)


NetInfo
createTcpSocketServer(int port) {
    int sock;
    socklen_t length;
    struct sockaddr_in server;

    memset(&server, 0, sizeof(server));

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        LOGE("opening stream socket");
        exit(EXIT_FAILURE);
        /* NOTREACHED */
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = port;
    if (bind(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        LOGE("binding stream socket");
        exit(EXIT_FAILURE);
        /* NOTREACHED */
    }

    length = sizeof(server);
    if (getsockname(sock, (struct sockaddr *) &server, &length) < 0) {
        LOGE("getting socket name");
        exit(EXIT_FAILURE);
        /* NOTREACHED */
    }

    LOGD("Tcp Socket has port #%d\n", ntohs(server.sin_port));

    if (listen(sock, BACKLOG) < 0) {
        LOGE("listening");
        exit(EXIT_FAILURE);
        /* NOTREACHED */
    }
    NetInfo info;
    info.s_fd = sock;
    info.s_port = server.sin_port;
    info.addr = server;
    return info;
}


NetInfo
createUdpSocketServer(int port) {
    int udpFd = -1;
    struct sockaddr_in server;
    socklen_t length;

    if ((udpFd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        LOGE("opening stream socket");
        exit(EXIT_FAILURE);
        /* NOTREACHED */
    }

    bzero(&server, sizeof(server));
    server.sin_port = port;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_INET;
    if (bind(udpFd, (const struct sockaddr *) &server, sizeof(server)) < 0) {
        LOGE("bind udp socket failed");
        exit(EXIT_FAILURE);
    }

    length = sizeof(server);
    if (getsockname(udpFd, (struct sockaddr *) &server, &length) < 0) {
        LOGE("getting socket name");
        exit(EXIT_FAILURE);
    }

    LOGD("Udp Socket has port #%d\n", ntohs(server.sin_port));

    NetInfo info;
    info.s_port = server.sin_port;
    info.s_fd = udpFd;
    info.addr = server;
    return info;
}

void
print_router_ip() {
    struct ifaddrs *ifaddr, *ifa;

    if (getifaddrs(&ifaddr) == -1) {
        LOGE("getifaddrs");
        return;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;

        if (ifa->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *sa = (struct sockaddr_in *) ifa->ifa_addr;
            LOGD("Router IP: %s\n", inet_ntoa(sa->sin_addr));
            break;
        }
    }

    freeifaddrs(ifaddr);
}


