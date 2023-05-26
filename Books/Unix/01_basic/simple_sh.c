//
// Created by Administrator on 2023/5/27.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

void handle_signal(int sig){
  switch (sig) {
    case SIGUSR1:{
      perror(strerror(errno));
    }
    default:
      break;
  }
}

int main(int argc,char *v[]){
  signal(SIGN)
}
