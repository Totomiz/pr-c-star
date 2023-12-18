//
// Created by Lenovot on 2023/12/18.
//

#ifndef MNT_C_PROJS_CLIONPROJECTS_PR_C_STAR_PROGRAMX_CHAT2_SOCK_H
#define MNT_C_PROJS_CLIONPROJECTS_PR_C_STAR_PROGRAMX_CHAT2_SOCK_H

typedef struct {
    int s_port;
    int s_fd;
} NetInfo;

NetInfo createUdpSocketServer(int port);

NetInfo createTcpSocketServer(int port);

void print_router_ip();



#endif //MNT_C_PROJS_CLIONPROJECTS_PR_C_STAR_PROGRAMX_CHAT2_SOCK_H
