//
// Created by Administrator on 2022/8/29.
//

#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int main() {
  /*
   * 格式化输出
   * 1. printf("format string",expr1,expr2,expr3,...)
   * */
  char sign = 'A';
  int age = 18;
  printf("class is-> %c,age is->%d,next age is->%d\n", sign, age, age + 1);

  int a, b;
  printf("input int number a+b:\n");
  scanf("%d+%d", &a, &b);
  printf("scanf value is a=%d b=%d sum=%d\n", a, b, a + b);

  short short_v = 2;
  int int_v = 10;
  unsigned int u_int_v = 65535;
  long long_v = 1000;
  long long long_long_v = 1000;
  float float_v = 1.3f;
  double double_v = 0.2345678901;
  printf("short=%d\t sizeof(short)=%zu\n", short_v, sizeof(short));
  printf("unsigned int=%d\t sizeof(unsigned int)=%zu\n", int_v, sizeof(int));
  printf("int=%d\t sizeof(int)=%zu\n", int_v, sizeof(int));
  printf("long=%lu\t sizeof(long)=%zu\n", long_v, sizeof(long));
  printf("long=%llu\t sizeof(long long)=%zu\n", long_long_v, sizeof(long long));
  printf("float(m.p=0.2) =%0.2f\t sizeof(float)=%zu\n", float_v, sizeof(float));
  printf("float(m.p=1.2) =%1.2f\t sizeof(float)=%zu\n", float_v, sizeof(float));
  printf("float(m.p=.6) =%.6f\t sizeof(float)=%zu\n", float_v, sizeof(float));
  printf("float(m.p=.10) =%.10f\t sizeof(float)=%zu\n", float_v, sizeof(float));
  printf("float(m.p=.10) =%.10lf\t sizeof(double)=%zu\n", double_v, sizeof(double));
  printf("float(m.p=.6) =%.6lf\t sizeof(double)=%zu\n", double_v, sizeof(double));

  printf("float(m.p=.6) =%.6lf\t sizeof(double)=%zu\n", double_v, sizeof(double));
  printf("%-p\n", "test1");
  char *p;
  p = "test";
  printf("%p\n", "test");
  printf("%p\n", p);
  printf("%p\n", *p);
  /*
   * 2.字符类型char
   * */
  char char_value = 'a';
  printf("char value=%c\n", char_value);

  /**
   * 3.转大写
   */
  if ('a' <= char_value && char_value <= 'z') {
	printf("upper char method normal:%c\n", char_value - 'a' + 'A');
	printf("upper char method(toupper) 2:%c\n", toupper(char_value));
  }
  return 0;
}