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
  //char str3[3] = "abc"; 不是一个正确的字符串定义,字符串是由字符数组表示的，以空字符 '\0' 结尾，表示字符串的结束。
  //正确的字符串定义应该是 char str3[4] = "abc";，这样可以确保有足够的空间来存储字符串及其终止符。
  //但作为字符数组时可以理解的。需要注意的是，上述的定义方式并不符合字符串的规范。

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

