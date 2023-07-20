#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>

// 获取用户输入的函数
char *getinput(char *buffer, size_t buflen) {
  printf("%s@tsh> ", getlogin());
  return fgets(buffer, buflen, stdin);
}

// SIGINT 信号处理函数
void sig_handle(int signo) {
  printf("\nCaught SIGINT (Signal #%d)!\n%s@tsh> ", signo, getlogin());
  (void) fflush(stdout);
}

int main(int argc, char *argv[]) {
  char buf[BUFSIZ];  // 存储用户输入的缓冲区
  pid_t pid;         // 子进程 ID
  int status;        // 进程状态

  // 注册 SIGINT 信号处理函数
  if (signal(SIGINT, sig_handle) == SIG_ERR) {
	fprintf(stderr, "signal error: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
  }

  // 循环读取用户输入
  while (getinput(buf, sizeof(buf))) {
	buf[strlen(buf) - 1] = '\0';  // 去除换行符
	int index = 0;
	char *temp;
	char *args[BUFSIZ];

	// 将用户输入分割成多个子串
	args[index++] = strtok(buf, " \n");
	while ((temp = strtok(NULL, " \n")) != NULL) {
	  args[index++] = temp;
	}
	args[index] = NULL;

	// 创建子进程执行命令
	if ((pid = fork()) == -1) {  // 失败处理
	  fprintf(stderr, "shell: can't fork: %s\n",
	          strerror(errno));
	  continue;
	} else if (pid == 0) {       // 子进程执行
	  execvp(args[0], args);     // 执行用户命令
	  fprintf(stderr, "shell: couldn't exec %s: %s\n", buf,
	          strerror(errno));  // 如果执行失败，则输出错误信息
	  exit(EX_UNAVAILABLE);      // 退出子进程
	}

	// 等待子进程结束
	if ((pid = waitpid(pid, &status, 0)) < 0) {
	  fprintf(stderr, "shell: waitpid error: %s\n",
	          strerror(errno));
	}
  }

  exit(EX_OK);  // 退出程序
}