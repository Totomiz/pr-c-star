//
// Created by Administrator on 2022/12/7.
//

#include <stdio.h>

int main() {
  int android, java, python,c;
  /*简单赋值*/
  android = 1;
  java = android;
  c = android + java * 10;
  /*复合赋值*/
  c = android = python = java * 10;
}