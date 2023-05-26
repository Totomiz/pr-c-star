//
// Created by Administrator on 2023/5/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int c, char *a[]) {
  FILE *fp;
  int num;

  fp = fopen("test.txt", "r");

  errno = 0;//每次使用前最好重置0
  if (fp == NULL) {
	printf("Error opening file: %s\n", strerror(errno));
  }

  fclose(fp);
  return 0;
}