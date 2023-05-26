//
// Created by Administrator on 2023/5/1.
//
#include <stdlib.h>
#include <stdio.h>
#include "apue.h"
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>

// int command(const char *string,char *outbuf,int outlen,char *errbuf,int errlen){
//   write(STDOUT_FILENO,outbuf,outlen)
// }

int main(int argc, char *argv[]) {
  int var;
  var = 99;
  pid_t fork_p = fork();

  printf("welcome %s",getlogin());
  if (fork_p > 0) {
    var=var+1;
    printf("var=%d pid=%d fork_pid= %d ppid=%d success\n",var,getpid(),fork_p,getppid());
  }else{
    printf("var=%d pid=%d fork_pid= %d ppid=%dfailed\n",var,getpid(),fork_p,getppid());
  }
  // getchar();

  // if (fork_p == -1) {
	// perror("fork()"); // 异常处理，输出更详细的错误信息
	// exit(EXIT_FAILURE);
  // }else if (fork_p == 0) {
	// printf("var=%d pid=%d fork_pid=%d ppid=%d success\n", var, getpid(), fork_p, getppid());
  //
	// fork_p = fork();
	// if (fork_p == -1) {
	//   perror("fork()"); // 异常处理，输出更详细的错误信息
	//   exit(EXIT_FAILURE);
	// }else if (fork_p == 0) {
	//   printf("var=%d pid=%d fork_pid=%d ppid=%d success\n", --var, getpid(), fork_p, getppid());
	// }else {
	//   exit(EXIT_SUCCESS);
	// }
  // }else {
	// wait(NULL);
  // }

  getchar();
  return 0;
}