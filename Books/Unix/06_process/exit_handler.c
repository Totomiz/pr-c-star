//
// Created by Administrator on 2023/6/17.
//

/* A simple illustration of exit handlers.  Note that exit handlers are
 * pushed onto a stack and thus execute in reverse order.
 *
 * Illustrate exiting at different times by invoking
 * this program as
 * ./a.out            exit handlers invoked after return from main
 * ./a.out 1          exit handlers invoked from within func
 * ./a.out 1 2        no exit handlers invoked
 * ./a.out 1 2 3      we call abort(3), no exit handlers invoked
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_exit1() {
  printf("#1 exit handler\n");
}

void my_exit2() {
  printf("#2 exit handler\n");
}

void func(int argc) {
  printf("In func.\n");
  if (argc == 2) {
	exit(EXIT_SUCCESS);
  } else if (argc == 3) {
	_exit(EXIT_SUCCESS);
  } else if (argc == 4) {
	abort();
  } else {
    printf("fun other.\n");
  }
}

int main(int argc, char *argv[]) {
  if (atexit(my_exit1) != 0) {
	perror("can't register my_exit1");
	exit(EXIT_FAILURE);
  }
  if (atexit(my_exit2) != 0) {
	perror("can't register my_exit2");
	exit(EXIT_FAILURE);
  }
  func(argc);
  printf("main is done\n");
  return EXIT_SUCCESS;
}
