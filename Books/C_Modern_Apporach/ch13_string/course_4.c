//
// Created by Administrator on 2023/2/27.
//
#include <stdio.h>
#include <string.h>


/*
 * �����ַ����е��ַ�
 * */

int count_spaces(const char *s) {
  int count = 0;
  for (; *s != '\0'; s++) {
	if ((*s) == ' ') {
	  count++;
	}
  }

  return count;
}

int main() {

  char str[] = "we have fun yet!";
  int count = count_spaces(str);
  puts(str);
  printf("space count=%d", count);

  return 0;
}


