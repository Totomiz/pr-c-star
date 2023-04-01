//
// Created by Administrator on 2023/2/27.
//
#include <stdio.h>

int main() {
  //惯用法，由于末尾空字符
#define STR_LENGTH 8
  char name[STR_LENGTH + 1] = "abc";

  char *p_str = "hello world!";
  char c_array[] = {'a', 'b', 'c'};
  char c_array2[] = "abc2";
  char *p;
  p=c_array;//p作为字符串之前,必须把p指向字符数组

  int size_name = (sizeof(name) / sizeof(name[0]));
  for (int i = 0; i < size_name; ++i) {
	printf("name# %c total=%d\n", name[i], size_name);
  }

  int i = 0;
  while (((int) *p_str) != '\0') {
	printf("p_str#%d %c\n", i++, *(p_str++));
  }
  printf("p_str#end %c\n", *p_str);
  return 0;
}

