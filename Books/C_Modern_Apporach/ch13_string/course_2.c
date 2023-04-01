//
// Created by Administrator on 2023/2/27.
//
#include <stdio.h>
#include <string.h>
#define  NEXT "(y/n)"
#define  YES "y"
#define  NO "n"


int main() {

  char str[] = "we have fun yet!";
  char *str2 = "we have fun2 yet! 酷";
  char str3[3] = "abc";

  //1.字符串写
  printf("%.6s\n", str);
  printf("%s\n", str2);
  printf("%s\n", str3);

  //2.字符串读
  char str_a[3] = "abc";

  /*
   *使用scanf()方式
   */
  while (1) {
	printf("input by scanf():\n");
	scanf("%s", str_a);
	puts(str_a);
	int size_s_str = (sizeof(str_a) / sizeof(str_a[0]));
	printf("s_a size=%d \n", size_s_str);//本机测试输入超过3任然能显示（内存越界可能产生莫名其妙的结果）
	printf("重新输入%s?：\n", NEXT);
	scanf("%s", str_a);
	if (strcmp(str_a, NO) == 0) {
	  break;
	}
  }
  getchar();


  /*
   *使用gets()方式
   */
  while (1) {
	printf("input by gets():\n");
	gets(str_a);
	puts(str_a);
	int size_s_str = (sizeof(str_a) / sizeof(str_a[0]));
	printf("s_a size=%d \n", size_s_str);//本机测试输入超过3任然能显示（内存越界可能产生莫名其妙的结果）
	printf("重新输入%s?：\n", NEXT);
	gets(str_a);
	if (strcmp(str_a, NO) == 0) {
	  break;
	}
  }

  return 0;
}

