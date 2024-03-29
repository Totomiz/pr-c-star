//
// Created by Administrator on 2022/8/29.
//

#include <stdio.h>
#include <ctype.h>

int main() {
  /*
   * 格式化输出
   * 1. printf("format string",expr1,expr2,expr3,...)
   * */
  short short_v = 2;
  unsigned short int u_short_v = 2;
  int int_v = 10;
  unsigned int u_int_v =19;
  long long_v = 1000;
  unsigned long u_long_v=1009;
  long long long_long_v = 10000;
  unsigned long long u_long_long_v = 10009;
  float float_v = 1.3f;
  double double_v = 0.2345678901;
  long double long_double_v = 0.2345678901;
  printf("short=%hd\t sizeof(short)=%zu\n", short_v, sizeof(short));
  printf("unsigned short=%hu\t sizeof(unsigned short)=%zu\n", u_short_v, sizeof(unsigned short));
  printf("int=%d\t sizeof(int)=%zu\n", int_v, sizeof(int));
  printf("unsigned int=%u\t sizeof(unsigned int)=%zu\n", u_int_v, sizeof(unsigned int));
  printf("long=%ld\t sizeof(long)=%zu\n", long_v, sizeof(long));
  printf("unsigned long=%lu\t sizeof(unsigned long)=%zu\n", u_long_v, sizeof(unsigned long));
  printf("long long=%lld\t sizeof(long long)=%zu\n", long_long_v, sizeof(long long));
  printf("unsigned long long=%llu\t sizeof(unsigned long long)=%zu\n", u_long_long_v, sizeof(unsigned long long));
  printf("float(m.p=0.2) =%0.2f\t sizeof(float)=%zu\n", float_v, sizeof(float));
  printf("float(m.p=1.2) =%1.2f\t sizeof(float)=%zu\n", float_v, sizeof(float));
  printf("float(m.p=.6) =%.6f\t sizeof(float)=%zu\n", float_v, sizeof(float));
  printf("float(m.p=.10) =%.10f\t sizeof(float)=%zu\n", float_v, sizeof(float));
  printf("float(m.p=.10) =%.10lf\t sizeof(double)=%zu\n", double_v, sizeof(double));
  printf("float(m.p=.6) =%.6lf\t sizeof(double)=%zu\n", double_v, sizeof(double));
  printf("float(m.p=.6) =%.6Lf\t sizeof(double)=%zu\n", long_double_v, sizeof(long double));
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

  /**
   * 4.typedef 优点，易理解，修改
   */
  typedef int STATUS;
  STATUS status_a = 100;
  printf("tpyedef status:%d\n", status_a);

  /**
   * 5.读写字符scanf()/printf()
   * 不会跳过空白字符
   */
  char scanf_char;
  printf("input a char (by scanf method):\n");
  scanf("%c", &scanf_char);
  printf("out you char value(by printf):%c\t\n", scanf_char);

  while (getchar() != '\n');
  printf("Skip rest of line...\n");
  /**
   * 6.读写字符
   * getChar()/ 读取输入字符，一次只能单字符，不会跳过空白字符
   * putChar(ch) 一次只能单字符输出
   *
   */

  printf("\ninput (by getchar() single char ):");
  int get_char = getchar();
  putchar(get_char);

  printf("\n__________________\n");
  printf("output (by getChar()) :%c\n", get_char);

  printf("+++++++++++++++++++++\n");
  printf("++++++input to output++++++\n");
  while ((get_char = getchar()) != EOF) {
	putchar(get_char);
  }
  return 0;
}