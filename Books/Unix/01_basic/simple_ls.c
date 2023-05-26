//
// Created by Administrator on 2023/5/26.
//

#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  DIR *dir = NULL;
  struct dirent *df;
  if (argc != 2) {
	fprintf(stderr, "usage: %s dirent_name", argv[0]);
	exit(EXIT_FAILURE);
  }
  errno = 0;
  if ((dir = opendir(argv[1])) == NULL) {
	fprintf(stdout, "unable to open '%s' %s",argv[1], strerror(errno));
	exit(EXIT_FAILURE);
  }

  while ((df = readdir(dir)) != NULL) {
	fprintf(stdout, "%s\n", df->d_name);
  }

  exit(EXIT_SUCCESS);
}