//
// Created by Administrator on 2022/11/3.
//
#include <stdio.h>
#define N 10

int main() {
  // 用指针作为数组名
  int a[] = {1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, *p = a, *q = &a[0], *k;
  k = a;
  // 三种效果相同
  for (int i = 0; i < N; ++i) {
	printf("p[%d]=%d\n", i, p[i]);//编译器把p[i]当作*（p+i) 可理解为对指针的加运算后，再使用间接寻址运算符
	printf("q[%d]=%d\n", i, q[i]);
	printf("k[%d]=%d\n", i, k[i]);
  }
  return 0;
}

