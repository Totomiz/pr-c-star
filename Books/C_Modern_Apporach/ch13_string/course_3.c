//
// Created by Administrator on 2023/2/27.
//
#include <stdio.h>
#include <string.h>

/*
 * 定义一个不跳过空白，在换行符停止（不存储），忽略额外字符的`read_line()`函数
 * */
int read_line(char[], int);
int read_line(char str[], int n) {
  int ch, i = 0;
  while ((ch = getchar()) != '\n') {
	if (i < n) {
	  str[i++] = ch;
	}
  }
  str[i] = '\0'; //手动加字符结尾
  return i;
}

int main() {

  char str[] = "we have fun yet!";
  int length = read_line(str, 4);
  puts(str);
  printf("length=%d",length);
  return 0;
}

