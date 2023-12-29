//
// Created by Lenovot on 2023/12/18.
//

#ifndef MNT_C_PROJS_CLIONPROJECTS_PR_C_STAR_PROGRAMX_CHAT2_SOCK_H
#define MNT_C_PROJS_CLIONPROJECTS_PR_C_STAR_PROGRAMX_CHAT2_SOCK_H

#include <netinet/in.h>

#ifndef PX_LOG_H
#define PX_LOG_H

#define LOGD(...) do{ \
                        printf(__VA_ARGS__);  \
                        printf("\n"); \
                    } while(0)

#define LOGE(...) do{ \
                        fprintf(stderr,__VA_ARGS__); \
                        printf(": %s\n",strerror(errno)); \
                    } while(0)

#endif //PX_LOG_H

typedef struct {
    int s_port;
    int s_fd;
    struct sockaddr_in addr;
} NetInfo;

typedef void (*Callback)(char *);

NetInfo createUdpSocketServer(int port);

NetInfo createTcpSocketServer(int port);

extern void handTcpSocket(int fd, Callback callback);

extern void handUdpSocket(int fd, Callback callback);

void print_router_ip();


#endif //MNT_C_PROJS_CLIONPROJECTS_PR_C_STAR_PROGRAMX_CHAT2_SOCK_H
