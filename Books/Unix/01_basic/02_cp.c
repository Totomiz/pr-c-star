//
// Created by Administrator on 2023/5/22.
//
#include "apue.h"
#define BufferSize BUFSIZ
int main(int c, char *a[]) {
  int n;
  char buf[BufferSize];
  while ((n = read(STDIN_FILENO, buf, BufferSize)) > 0) {//n 为实际读取到的字节数，可能不足BufferSize的长度
	if (write(STDOUT_FILENO, buf, n) != n) // 注意第三个参数为n，确保只将已经读取到的有效数据写入文件，从而保证程序的正确性和稳定性
	  err_sys("write error");
  }
  if (n < 0)
	err_sys("read error!");
  exit(0);

}