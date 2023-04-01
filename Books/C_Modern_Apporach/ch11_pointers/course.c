//
// Created by Administrator on 2022/11/3.
//

#include <stdio.h>

//指针参数函数原型，可加上名字
void decompose(double, long *, double *);

/**
 * 指针作为参数
 * 解决值传递时候无法改变实际参数的变量的问题
 * @param x
 * @param int_part
 * @param frac_part
 * @return
 */
void decompose(double x, long *int_part, double *frac_part) {
  *int_part = (long) x;
  *frac_part = x - *int_part;
}

/**
 * 指针作为返回值
 * @return
 */
int *find_middle(int n, int a[n]) {
  return &a[n / 2];
}

int *find_max(int *a, int *b) {
  if (*a > *b) {
	return a;
  } else {
	return b;
  }
}

int main() {
  /**
   * 定义指针
   */
  int i, j, *p, *q;
  int h = 0, *k = &h;
  i = 1;
  j = 2;

  //取址运算符&
  p = &i; //指针指向变量i的地址
  q = &j;

  //间接寻址运算符*，访问存储在对象中的内容
  printf("exec 1: i=%d,j=%d,*p=%d,*q=%d\n", i, j, *p, *q);

  q = p;//把把p的内容（即i的地址）复制给q,q指向了p指向的地方
  printf("exec 2: i=%d,j=%d,*p=%d,*q=%d\n", i, j, *p, *q);
  *q = *p;// *p指向的值（此处为i的值）复制到q指向的对象变量中
  printf("exec 2: i=%d,j=%d,*p=%d,*q=%d\n", i, j, *p, *q);

  double pi = 3.1415926;
  long int_part;
  double frac_part;
  // 函数用指针作为参数，改变变量的值
  decompose(pi, &int_part, &frac_part);
  printf("pi int_part=%lu, frac_part=%f\n", int_part, frac_part);
  printf("find max:%d\n", *find_max(&i, &j));
  printf("find middle:%d\n", *find_middle(3, (int[]) {1, 2, 3}));
  return 0;
}