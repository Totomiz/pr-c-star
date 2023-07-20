//
// Created by Administrator on 2023/5/26.
//

#include <stdio.h>      //提供输入输出函数定义
#include <dirent.h>     //提供读取目录和目录数据结构定义
#include <errno.h>      //提供错误代码定义
#include <stdlib.h>     //提供 exit() 函数定义
#include <string.h>     //提供 strerror() 函数定义

int main(int argc, char *argv[]) {
  DIR *dir = NULL;                //定义指向目录数据结构的指针
  struct dirent *df;              //定义指向目录项数据结构的指针
  if (argc != 2) {                //检查命令行参数个数是否为2
	fprintf(stderr, "usage: %s dirent_name", argv[0]);   //输出使用说明
	exit(EXIT_FAILURE);           //退出程序
  }
  errno = 0;                      //将错误代码初始化为0
  if ((dir = opendir(argv[1])) == NULL) {    //尝试打开指定目录，如果失败则输出错误信息
	fprintf(stdout, "unable to open '%s' %s", argv[1], strerror(errno));
	exit(EXIT_FAILURE);           //退出程序
  }

  while ((df = readdir(dir)) != NULL) {      //循环读取目录中的每个目录项
	fprintf(stdout, "%s\n", df->d_name);     //输出目录项名称
  }

  exit(EXIT_SUCCESS);             //正常结束程序
}