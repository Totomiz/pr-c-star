//
// Created by Administrator on 2023/5/27.
//

/*
 * 一个简单的示例程序，展示如何使用signal()函数来捕获和处理SIGINT信号：
 *
 * 这个例子中，当程序接收到SIGINT信号（通常由CTRL+C触发）时，
 * 它会执行sig_int_handler()函数并输出一条消息，然后退出程序并返回信号编号。
 * 如果不捕获SIGINT信号，则默认行为是终止进程。在程序执行过程中，我们使用一个无限循环来等待信号的到来。
 * */


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