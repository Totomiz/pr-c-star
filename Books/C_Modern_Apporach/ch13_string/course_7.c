//
// Created by Administrator on 2023/2/28.
//

#include <stdio.h>

/*
 * 命令行参数
 * 如：ls -l count.c
 * arg[0]程序名 剩余为余下命令参数，最后附加一个空指针argv[argc]=NULL
 */

int main(int argc,char* argv[]) {
  for (int i = 0; i <= argc; ++i) {
    printf("%d=%s\n",i,argv[i]);
  }
  char **p;
  for (p=&argv[0];*p!=NULL;p++){
    printf("%s\n",*p);
  }
  return 0;
}