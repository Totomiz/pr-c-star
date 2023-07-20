#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_LINE 80 // 最大命令行字符数

void
sig_int(int signo) {
  printf("\nCaught SIGINT (Signal #%d)!\n$$ ", signo);
  (void) fflush(stdout);
}

int main(void) {
  char *args[MAX_LINE / 2 + 1]; // 命令行参数数组
  int should_run = 1; // 控制循环变量

  if (signal(SIGINT, sig_int) == SIG_ERR) {
	fprintf(stderr, "signal error: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
  }

  fprintf(stdout, "welcome osh shell,%s \n", getlogin());

  while (should_run) {

	printf("osh> ");
	fflush(stdout);

	// 读取用户输入的命令行
	char input[MAX_LINE];
	fgets(input, MAX_LINE, stdin);

	// 将命令行按照空格符拆分成命令参数数组
	int argc = 0;
	args[argc] = strtok(input, " \n");
	while (args[argc] != NULL) {
	  argc++;
	  args[argc] = strtok(NULL, " \n");
	}
	args[argc] = NULL;

	// 如果用户输入了 exit 命令，则退出 shell
	if (argc>1 && strcmp(args[0], "exit") == 0) {
	  should_run = 0;
	  continue;
	}

	// 创建子进程并执行命令
	pid_t pid = fork();
	if (pid == 0) { // 子进程

	  execvp(args[0], args);
	  fprintf(stderr, "Error: command not found\n");
	  exit(EXIT_FAILURE);
	} else if (pid > 0) { // 父进程
	  waitpid(pid, NULL, 0);
	} else { // fork 函数失败
	  fprintf(stderr, "Error: fork failed\n");
	  exit(EXIT_FAILURE);
	}
  }

  exit(EXIT_SUCCESS);
}