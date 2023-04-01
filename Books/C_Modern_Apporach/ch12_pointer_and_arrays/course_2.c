//
// Created by Administrator on 2022/11/3.
//
#include <stdio.h>
#define N 10

int main() {
  // Q&A 有些编译器来说，实际上依靠下标的循环产生更好的代码
  int a[] = {1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, *p;
  for (p = &a[0]; p < &a[N]; p++) {
	printf("%d\n", *p);
  }
  /* 指针运算符合++运算符的组合
   *
   *
   *++++++++++++++++++++++++++++
   | 表达式 | 含义 |
   | --- | --- |
   | *p++或*(p++) |自增前表达式的值是*p,以后再自增p  |
   | *(p)++       |自增前表达式的值是*p,以后再自增*p  |
   | *++p或*(++p) |先自增p,自增后的表达式的值是*p |
   | ++*p或++(*p) |先自增*p,自增后的表达式的值是*p |
   *
   * */
  return 0;

}

