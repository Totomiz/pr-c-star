//
// Created by Administrator on 2023/4/3.
//

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

CString read_line() {
  CString s = NULL;
  int size = 0, capacity = 1;
  s = (CString) malloc(sizeof(char) * capacity);
  if (s == NULL) {
	printf("错误：内存分配失败。\n");
	exit(EXIT_FAILURE);
  }
  char c;
  while ((c = getchar()) != '\n') {
	s[size++] = c;
	if (size == capacity) {
	  capacity *= 2;
	  s = (CString) realloc(s, capacity * sizeof(char));
	  if (s == NULL) {
		printf("错误：内存分配失败。\n");
		exit(EXIT_FAILURE);
	  }
	}
  }
  s[size] = '\0';
  return s;
}