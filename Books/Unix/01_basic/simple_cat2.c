//
// Created by Administrator on 2023/5/26.
//
#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BF 4096
int main(int c, char *v[]) {
  int n;
  char buff[BF];
  errno = 0;
  while ((n = read(STDIN_FILENO, buff, BF)) > 0) {
	if (write(STDOUT_FILENO, buff, n) != n) {
	  fprintf(stderr, "Fail write:%s", strerror(errno));
	  exit(EXIT_FAILURE);
	}
  }
  if (n < 0) {
	fprintf(stderr, "Fail read:%s", strerror(errno));
	exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}