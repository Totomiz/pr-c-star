//
// Created by Administrator on 2023/6/17.
//



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern char **environ;

/*
 * gcc -e foo1 -g entry.c -lc -o entry
 */
int foo1() {
  printf("No main, foo1 exec!");
  // return 0;
  exit(EXIT_SUCCESS);//注意必须要有
}

int main(int argc, char *argv[], char *env[]) {
  printf("OK, main exec!");

  // 通过environ变量访问
  char **p;
  for (p = &environ[0]; *p != NULL; p++) {
	printf("%s\n", *p);
  }

  // 通过参数env访问
  char **q;
  for (q = &environ[0]; *q != NULL; q++) {
	printf("%s\n", *q);
  }

  // 获取其中一项
  char *home = getenv("HOME");
  printf("getenv:: $s", home);

  exit(EXIT_SUCCESS);
}