//
// Created by Administrator on 2022/11/3.
//
#include <stdio.h>
#define N 10

int main() {
  // 数组名作为指针
  int a[] = {1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, *p,*q;
  // 原始写法
  for (q = &a[0]; q < &a[N]; q++) {
	printf("*q=%d ", *q);
  }

  int sum = 0;
  // 惯用法
  for (p = a; p < a + N; p++) {//a+N理解为，将a当作指针，然后做了指针的加法运算
	sum += *p;
	printf("\n sum = %d *p=%d", sum,*p);
  }

  return 0;

}

