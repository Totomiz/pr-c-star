//
// Created by Administrator on 2023/4/1.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a, b;


  if (fflush(stdin) != 0) {
	exit(EXIT_FAILURE);
  };

  scanf("%d", &a);
  printf("a=%d", a);
  //解决输入缓冲区，可能引起的问题，如，一次性输入两个数，中间加上空格，不清空缓冲区就会同时输出a,b值
  setbuf(stdin,NULL);
  scanf("%d", &b);

  printf("b=%d", b);
  exit(0);
}