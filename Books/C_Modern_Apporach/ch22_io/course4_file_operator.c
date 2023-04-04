//
// Created by Administrator on 2023/4/3.
//

#include <stdio.h>
#include <stdlib.h>
#include "../common/utils.h"
#include <string.h>
#include <errno.h>

#define FILENAME "file_op_test.txt"

#ifdef _WIN32
#define CONSOLE_DEVICE "CON"
#else
#define CONSOLE_DEVICE "/dev/tty"
#endif

void input_file() {
  errno = 0;
  FILE *fp = fopen(FILENAME, "w");
  if (fp == NULL) {
	printf("Cant open %s\n", FILENAME);
	if (errno != 0) {
	  perror("input_file error:");
	}
	exit(EXIT_FAILURE);
  }
  println("input something:");

  CString str = read_line();
  printf("%s", str);
  fputs(str, fp);
  // fputc('\n', fp);
  fclose(fp);
  free(str);
}

/*
 * 打印文件
 */
void print_file() {
  errno = 0;
  FILE *fp = fopen(FILENAME, "r");
  if (fp == NULL) {
	printf("Cant open %s\n", FILENAME);
	if (errno != 0) {
	  perror("print_file error:");
	  exit(EXIT_FAILURE);
	}
  }

  // }
  char c;
  while ((c = fgetc(fp)) != EOF) {
	putchar(c);
  }
  fclose(fp);
}

/**
 * 可以使用 freopen() 函数将标准输出流重新附加到控制台。以下是一个示例实现：
 * To answer your question, CON is a special file in Windows that represents the console output.
 * When a program writes to stdout and the output is redirected to a file,
 * the output is written to the file instead of the console.
 * By using freopen() to attach stdout to the CON file, the output stream is redirected back to the console.
 * In the code you provided,
 * the restore_stdout() function uses freopen() to attach stdout to the console by opening the CON file in write mode
 * and redirecting the output stream to it. If the file cannot be opened,
 * an error message is printed and the program exits with a failure status.
 */
void restore_stdout() {
  // 将 stdout 重新附加到控制台上（Windows 下是 CON，Unix/Linux 下是 /dev/tty）
  FILE *fp = freopen(CONSOLE_DEVICE, "w", stdout);
  if (fp == NULL) {
	printf("Error: Cannot restore stdout");
	exit(EXIT_FAILURE);
  }
}

/**
 * 重打开附加流 freopen 方法的使用
 * 将标准输出流stdout附加到文件filename，以追加的方式
 * 不断读取标准输入流stdin的内容s,将s写入标准输出流中，从而添加到文件
 * 1. stdout attach to file
 * 2. stdin -> string ->stdout -> file
 * 3. 输入exit,退出循环，重定向输出流到控制台
 * @param filename
 */
void attach_to_file(const char *filename) {
  printf("Enter input, and (exit) quit input: \n");
  setbuf(stdout, NULL);
  FILE *fp = freopen(filename, "a+", stdout);
  if (fp == NULL) {
	printf("Error: Cannot open file %s", filename);
	exit(EXIT_FAILURE);
  }
  char input[10];

  while (1) {
	char *s = fgets(input, sizeof(input), stdin);
	if (strncmp("exit", input, 4) == 0) {
	  break;
	}
	fputs(s, stdout);
	fflush(stdout);
  }
  fclose(fp);
  restore_stdout();
  printf("end\n");
}

/**
 * 输入保存到文件
 * @param filename
 */
void save_input_to_file(const char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
	perror("Error opening file");
	exit(EXIT_FAILURE);
  }
  fflush(stdin);//防止文件第一行空行
  char input[100];
  printf("Enter input:and (exit) quit input: \n");
  // 当 fgets() 成功地从流 stream 中获取一行数据时，它会返回非空值（即所获取数据所在缓冲区地址），否则返回 NULL
  // 在 while 循环条件语句处，只有当 fgets() 返回非空值时才会继续执行循环体内部代码块。
  while (fgets(input, sizeof(input), stdin)) {
	if (strncmp("exit", input, 4) == 0) {
	  break;
	}
	fputs(input, fp);
	fflush(fp);// 刷新 文件 缓冲区
  }
  fclose(fp);
}

/**
 * 创建临时文件，写入字符，然后打印，在window创建临时文件由于权限导致失败，在我的虚拟机linux环境上测试通过
 */
void temp_file_no_name() {
  errno=0;
  FILE *fp = tmpfile();
  if (fp == NULL) {
	printf("create file failed: %s\n", strerror(errno));
	return;
  }

  fputs("this is temp file",fp);
  char ch;
  //重置指针到开头
  rewind(fp);
  while ((ch=fgetc(fp))!=EOF){
    printf("%c",ch);
    fflush(fp);
  }
  fclose(fp);
}

/**
 * 创建临时文件（有名字），写入字符，然后打印，在window创建临时文件由于权限导致失败，在我的虚拟机linux环境上测试通过
 */
void temp_file_with_name(){
  errno=0;
  char *name=tmpnam(NULL);
  FILE *fp= fopen(name,"w+");
  if (fp == NULL) {
	printf("create file failed: %s\n", strerror(errno));
	return;
  }

  printf("temp file name is :%s",name);
  fputs("this is temp file",fp);
  char ch;
  //重置指针到开头
  rewind(fp);
  while ((ch=fgetc(fp))!=EOF){
	printf("%c",ch);
	fflush(fp);
  }
  fclose(fp);
}

int main() {
  int mode;

  while (1) {
	printf("\ninput mode:\n");
	printf("0 quit  1 input_file 2. print file\n");
	printf("3 use freopen attach stdout stream\n");
	printf("4 save stdin input to file\n");
	printf("5 tmpfile no name\n");
	printf("6 temp file with name\n");
	setbuf(stdin, NULL);

	scanf("%d", &mode);
	switch (mode) {
	  case 0:exit(0);
	  case 1: {
		setbuf(stdin, NULL);
		input_file();
		break;
	  }
	  case 2: {
		print_file();
		break;
	  }
	  case 3: {
		attach_to_file(FILENAME);
		break;
	  }
	  case 4: {
		save_input_to_file(FILENAME);
		break;
	  }

	  case 5: {
		temp_file_no_name();
		break;
	  }

	  case 6: {
		temp_file_with_name();
		break;
	  }
	  default:break;
	}
  }
}