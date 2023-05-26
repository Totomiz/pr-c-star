//
// Created by Administrator on 2023/5/27.
//

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// 信号处理程序
void sig_int_handler(int signum) {
  printf("Received SIGINT signal!\n");
  exit(signum);
}

int main() {
  // 注册SIGINT信号处理程序
  signal(SIGINT, sig_int_handler);

  printf("Waiting for SIGINT signal...\n");

  while (1) {}

  return 0;
}