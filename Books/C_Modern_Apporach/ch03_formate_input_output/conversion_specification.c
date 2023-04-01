//
// Created by Administrator on 2022/12/7.
//
#include <stdio.h>
int main(){
  char *d_spec="%d/t%i";
  printf("%s\n",d_spec);
  int a;
  printf("hello\b\r%n",&a);
  printf("%d",a);
  printf("sda\a\f");
}
