//
// Created by Administrator on 2023/2/27.
//
#include <stdio.h>
#include <string.h>

/*
 * ����һ���������հף��ڻ��з�ֹͣ�����洢�������Զ����ַ���`read_line()`����
 * */
int read_line(char[], int);
int read_line(char str[], int n) {
  int ch, i = 0;
  while ((ch = getchar()) != '\n') {
	if (i < n) {
	  str[i++] = ch;
	}
  }
  str[i] = '\0'; //�ֶ����ַ���β
  return i;
}

int main() {

  char str[] = "we have fun yet!";
  int length = read_line(str, 4);
  puts(str);
  printf("length=%d",length);
  return 0;
}

