//
// Created by Administrator on 2023/3/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "read_line.h"



int main() {
  long int size = 1024 * 1024  * 1; //计算出需要分配的内存大小为1GB
  char *memory = (char *) malloc(size); //使用malloc函数动态分配内存
  if (memory == NULL) { //如果无法成功分配内存，则输出错误信息并退出程序
	printf("Failed to allocate memory!");
	exit(1);
  }

  srand(time(NULL)); //初始化随机数种子

  for (long int i = 0; i < size; ++i) {
	memory[i] = rand() % 256; //向每个字节位置写入一个随机数（范围从0到255）
  }

  printf("Successfully allocated and filled %ld bytes of memory.", size);
  int i = 0, j = 0;
  int *restrict p;//受限指针
  int * q;//受限指针
  p= malloc(sizeof(int ));
  *p=100;
  printf("%d",*p);
	q=p;
	*q=200;
  printf("%d %d",*q, *p);
  while (1) {
	String input = read_line();
	printf("%s", input);
	if (strcmp(input, "free") == 0 && i == 0) {
	  free(memory);
	  i++;
	}
	if (strcmp(input, "exit") == 0) {
	  break;
	}
    free(input);
  } //这里故意让程序陷入死循环，模拟没有释放掉已经使用过的大量内存在运行时

  return 0;
}

