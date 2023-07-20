//
// Created by Administrator on 2023/6/4.
//

#include "apue.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef SLEEP
#define SLEEP 3
#endif

const char *file_path = "./newfile.txt";

void createFailedFile() {
  int fd;
  printf("check '%s' exists...\n", file_path);
  system("ls -l ./newfile.txt");
  printf("Try to create '%s' with O_RDWR ...\n", file_path);
  if ((fd = open("./newfile.txt", O_RDWR)) == -1) {
	perror("unable to create './newfile.txt' :");
	//exit(EXIT_FAILURE);
	return;
  }

  printf("'%s' created. File descriptor is: %d\n", file_path, fd);
  close(fd);

}

void createSuccessFile() {
  int fd;
  printf("check '%s' exists...\n", file_path);
  system("ls -l ./newfile.txt");
  printf("Try to create '%s' with O_RDWR | O_CREAT | O_TRUNC ...\n", file_path);
  if ((fd = open(file_path, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU)) == -1) {
	perror("unable to create './newfile.txt' :");
	//exit(EXIT_FAILURE);
	return;
  }

  printf("'%s' created. File descriptor is: %d\n", file_path, fd);
  close(fd);

}

void writeFile() {
  int fd;
  if ((fd = open(file_path, O_RDWR)) == -1) {
	perror("unable to O_RDWR './newfile.txt' :");
	//exit(EXIT_FAILURE);
	return;
  }

  int wn, total_written = 0;
  size_t n = 4;
  const char *content = "abcdefgABCDEFG";
  while (total_written < strlen(content)) {
	wn = write(fd, content + total_written,
	           strlen(content) - total_written);
	if (wn == -1) {
	  // 写入出错，进行错误处理
	  perror("write err");
	  break;
	}
	total_written += wn;
  }
  close(fd);

}

void readFile() {
  int fd, n;
  if ((fd = open(file_path, O_RDONLY)) == -1) {
	perror("unable to O_RDWR './newfile.txt' :");
	return;
  }
  char bytes[1024];

  while ((n = read(fd, bytes, 1024)) > 0) {
	// 将数据写入标准输出
	write(STDOUT_FILENO, bytes, n);
  }
  close(fd);
}

void seekFile() {
  int fd;
  if ((fd = open(file_path, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU)) == -1) {
	perror("unable to create './newfile.txt' :");
	//exit(EXIT_FAILURE);
	return;
  }
  __off_t offset = 0;
  int seek;
  if ((seek = lseek(fd, offset, SEEK_CUR)) == -1) {
	perror("seek err: ");
  } else {
	fprintf(stdout, "lseek SEEK_CUR offset=%ld : seek=%d", offset, seek);
  }

}

void keepForSecond() {
  system("ls -ls newfile.txt");
  printf("\n");
  sleep(SLEEP);
}

int main(int argc, char *argv[]) {
  createFailedFile();
  keepForSecond();

  createSuccessFile();
  keepForSecond();

  writeFile();
  system("cat newfile.txt");
  printf("\n");
  keepForSecond();

  readFile();
  keepForSecond();


  // seekFile();
  // keepForSecond();

  exit(EXIT_SUCCESS);
}