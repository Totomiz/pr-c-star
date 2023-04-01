//
// Created by Administrator on 2023/3/16.
//

#include <stdio.h>
#include "course1.h"

int value = 1;
int ext_value = 2;

int sum(int a, int b) {
  return a + b;
}

int main() {
  printf("%d %d\n", value, ext_value);
  ext_value = 3;
  printf("%d %d\n", value, ext_value);
  return 0;
}