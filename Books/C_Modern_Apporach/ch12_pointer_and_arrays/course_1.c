//
// Created by Administrator on 2022/11/3.
//
#include <stdio.h>

int main() {
  int a[] = {1, 2, 3, 5, 6, 7, 8, 9, 10};
  int *p = &a[0], *q = &a[6];
  //1. 加整数
  p += 4;
  printf("p %d\n", *p);

  //2. 减整数
  p -= 3;
  printf("p %d\n", *p);

  //3. 指针相减
  printf("q-p = %lld\n", q - p);

  //4. 指针比较(取决于在数组中的位置)
  printf("q>p:%d q<p:%d\n", q > p, q < p);

  //5. 复合常量的指针
  int *k = (int[]) {2, 4, 6, 8, 10};
  k += 4;
  printf("*K=%d\n", *k);

  return 0;

}

