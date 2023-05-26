//
// Created by Administrator on 2023/5/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main(int argc, char *argv[]) {
  errno = 0;
  int c;
  while ((c = fgetc(stdin)) != EOF) {
	if (putc(c, stdout) == EOF) {
	  fprintf(stderr, "Unable to write: %s", strerror(errno));
	  exit(EXIT_FAILURE);
	}
  }
  exit(EXIT_SUCCESS);

}