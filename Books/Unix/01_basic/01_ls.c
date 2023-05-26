//
// Created by Administrator on 2023/5/22.
//

#include "apue.h"
#include <dirent.h>
#include <bsd/stdlib.h>

int main(int argc, char *argv[]) {
  setprogname(argv[0]);
  DIR *dp;
  struct dirent *dirp;
  if (argc != 2)
	err_quit("usage: %s directory_name", getprogname());

  // 打开arg[1]目录,赋值给dp目录指针
  if ((dp = opendir(argv[1])) == NULL)
	err_sys("can't open %s", argv[1]);

  // 读取目录
  while ((dirp = readdir(dp)) != NULL)
	printf("%s\n", dirp->d_name);
  closedir(dp);
  exit(0);
}