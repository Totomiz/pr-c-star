//
// Created by Administrator on 2022/8/25.
//

#include <stdio.h>

int main() {
  /*
   * 1 printf
   * */
  printf("this is a simple c program\n");

  /*
   * 2
   *
   * 预处理->编译->链接
   *
   * gcc -o outfile srcfile [-w]
   * */
  printf("预处理->编译->链接 \n eg:gcc -o outfile srcfile [-w]");

  /* 3
   * 指令：#include "stdio.h"
   * 函数：type functionName(args){} 如 int main(){return 0;}
   * 语句：printf("this is a statements\n");
   * 显示：printf("xxx content");
   * 注释：如本段
   * */
  printf("\n");

  /**
   * 4.变量和赋值
   * 类型：short/int/long/float/double/char/..
   * 声明：int var_name; (变量名字)
   * 赋值：var_name = 8;
   * 显示变量值：printf("var_name: %d",var_name);
   * 初始化：int h=12,w=13,l=15;
   * 显示表达式的值：printf("%d",h+w+l);
   * */
  float f_value = 3.25f;
  printf("float value:%0.2f\n", f_value);

  /**
   * 5.读入输入
   * scanf("%d",&i) 读入一个整数，存入到i中
   */
  int scan_i;
  printf("input an integer:\n");
  scanf("%d", &scan_i);
  printf("scanf i=%d", scan_i);
  return 0;
}
