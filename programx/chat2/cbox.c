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

#define BACKLOG 5
#ifndef SLEEP
#define SLEEP   5
#endif

#include "unet/sock.h"

int
createSocket(void) {
    int sock;
    socklen_t length;
    struct sockaddr_in server;

    memset(&server, 0, sizeof(server));

    if ((sock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("opening stream socket");
        exit(EXIT_FAILURE);
        /* NOTREACHED */
    }

    server.sin_family = PF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = 0;
    if (bind(sock, (struct sockaddr *) &server, sizeof(server)) != 0) {
        perror("binding stream socket");
        exit(EXIT_FAILURE);
        /* NOTREACHED */
    }

    length = sizeof(server);
    if (getsockname(sock, (struct sockaddr *) &server, &length) != 0) {
        perror("getting socket name");
        exit(EXIT_FAILURE);
        /* NOTREACHED */
    }
    (void) printf("Socket has port #%d\n", ntohs(server.sin_port));

    if (listen(sock, BACKLOG) < 0) {
        perror("listening");
        exit(EXIT_FAILURE);
        /* NOTREACHED */
    }

    return sock;
}

void
handleSocket(int s) {
    int fd, rval;
    char claddr[INET_ADDRSTRLEN];
    struct sockaddr_in client;
    socklen_t length;

    length = sizeof(client);
    memset(&client, 0, length);

    if ((fd = accept(s, (struct sockaddr *) &client, &length)) < 0) {
        perror("accept");
        return;
    }


    do {
        char buf[BUFSIZ];
        bzero(buf, sizeof(buf));
        if ((rval = read(fd, buf, BUFSIZ)) < 0) {
            perror("reading stream message");
        }

        if (rval == 0) {
            (void) printf("Ending connection\n");
        } else {
            const char *rip;
            if ((rip = inet_ntop(PF_INET, &(client.sin_addr), claddr, length)) == NULL) {
                perror("inet_ntop");
                rip = "unknown";
            } else {
                (void) printf("Client (%s) sent: %s\n", rip, buf);
            }
        }
    } while (rval != 0);
    (void) close(fd);
}

void
handTcpSocket(int s, Callback callback) {
    int fd, rval;
    char claddr[INET_ADDRSTRLEN];
    struct sockaddr_in client;
    socklen_t length;

    length = sizeof(client);
    memset(&client, 0, length);

    if ((fd = accept(s, (struct sockaddr *) &client, &length)) < 0) {
        perror("accept");
        return;
    }


    do {
        char buf[BUFSIZ];
        bzero(buf, sizeof(buf));
        if ((rval = read(fd, buf, BUFSIZ)) < 0) {
            perror("reading stream message");
        }

        if (rval == 0) {
            (void) printf("Ending connection\n");
        } else {
            const char *rip;
            if ((rip = inet_ntop(PF_INET, &(client.sin_addr), claddr, length)) == NULL) {
                perror("inet_ntop");
                rip = "unknown";
            } else {
                (void) printf("Client (%s) sent: %s\n", rip, buf);
                if(callback !=NULL){
                    callback(buf);

                }
            }
        }
    } while (rval != 0);
    (void) close(fd);
}

void handleMs(char *msg) {
    LOGD("msg == %s", msg);
}

/*
 * This program uses select() to check that someone is trying to connect
 * before calling accept().
 */
int
main() {
    int s1, s2;

    NetInfo a = createUdpSocketServer(0);
    NetInfo b = createTcpSocketServer(0);
    s1 = a.s_fd;
    s2 = b.s_fd;
    LOGD("THIS");
    print_router_ip();
    (void) printf("s-》 %d , %d\n", s1, s2);


    for (;;) {
        fd_set ready;
        struct timeval timeout;

        FD_ZERO(&ready);
        FD_SET(s1, &ready);
        FD_SET(s2, &ready);
        timeout.tv_sec = SLEEP;
        timeout.tv_usec = 0;
        if (select(s1 > s2 ? s1 + 1 : s2 + 1, &ready, 0, 0, &timeout) < 0) {
            perror("select");
            continue;
        }

        if (FD_ISSET(s1, &ready)) {
            handTcpSocket(s1, NULL);
        }
        if (FD_ISSET(s2, &ready)) {
            handTcpSocket(s2, handleMs);
//            handleSocket(s2);
        }
    }

    /* NOTREACHED */
}