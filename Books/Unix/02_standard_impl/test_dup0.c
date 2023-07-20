//
// Created by Administrator on 2023/5/29.
//

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main() {
  char buf[BUFSIZE];
  int fd, n;

  // 复制标准输入文件描述符
  fd = dup(STDIN_FILENO);

  // 从标准输入读取数据
  while ((n = read(fd, buf, BUFSIZE)) > 0) {
	// 将数据写入标准输出
	write(STDOUT_FILENO, buf, n);
  }

  return 0;
}
