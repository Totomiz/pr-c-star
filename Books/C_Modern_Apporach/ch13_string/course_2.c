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
  char *str2 = "we have fun2 yet! ��";
  char str3[3] = "abc";
  //char str3[3] = "abc"; ����һ����ȷ���ַ�������,�ַ��������ַ������ʾ�ģ��Կ��ַ� '\0' ��β����ʾ�ַ����Ľ�����
  //��ȷ���ַ�������Ӧ���� char str3[4] = "abc";����������ȷ�����㹻�Ŀռ����洢�ַ���������ֹ����
  //����Ϊ�ַ�����ʱ�������ġ���Ҫע����ǣ������Ķ��巽ʽ���������ַ����Ĺ淶��

  //1.�ַ���д
  printf("%.6s\n", str);
  printf("%s\n", str2);
  printf("%s\n", str3);

  //2.�ַ�����
  char str_a[3] = "abc";

  /*
   *ʹ��scanf()��ʽ
   */
  while (1) {
	printf("input by scanf():\n");
	scanf("%s", str_a);
	puts(str_a);
	int size_s_str = (sizeof(str_a) / sizeof(str_a[0]));
	printf("s_a size=%d \n", size_s_str);//�����������볬��3��Ȼ����ʾ���ڴ�Խ����ܲ���Ī������Ľ����
	printf("��������%s?��\n", NEXT);
	scanf("%s", str_a);
	if (strcmp(str_a, NO) == 0) {
	  break;
	}
  }
  getchar();


  /*
   *ʹ��gets()��ʽ
   */
  while (1) {
	printf("input by gets():\n");
	gets(str_a);
	puts(str_a);
	int size_s_str = (sizeof(str_a) / sizeof(str_a[0]));
	printf("s_a size=%d \n", size_s_str);//�����������볬��3��Ȼ����ʾ���ڴ�Խ����ܲ���Ī������Ľ����
	printf("��������%s?��\n", NEXT);
	gets(str_a);
	if (strcmp(str_a, NO) == 0) {
	  break;
	}
  }

  return 0;
}

