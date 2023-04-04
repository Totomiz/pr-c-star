//
// Created by Administrator on 2023/4/2.
//

#include <stdio.h>
#include <stdlib.h>

/*
 * 简单重定向输入输出
 * 用法1 demo <in.txt out.txt
 * echo "Hello World!" | ./demo
 */
int main(){
  int ch;
  while ((ch=getchar())!=EOF){
    putchar(ch);
  }
  return 0;
}