#include <stdio.h>
#include <stdlib.h>

// #define P(expr, ...)  printf(#expr "" __VA_ARGS__);expr
// #define P(expr, ...)  printf("%-30s", #expr); printf(""__VA_ARGS__);expr
#define P(expr, ...) do { \
    printf("%25s", #expr); \
    printf("" __VA_ARGS__); \
    expr; \
} while(0)//do while包裹多条语句，小技巧

#define BLUE 1
#define RED 2
#define GREEN 4
typedef unsigned int Bit_16;
typedef char *String;

/**
 * 将输入数number转换为2进制字符
 * @param number
 * @return
 */
char *binary(Bit_16 number) {
  int width = sizeof(Bit_16) * 8;

  String s1 = NULL;
  int size = 0, capacity = 1;
  s1 = (String) malloc(sizeof(char)); // 分配内存
  if (s1 == NULL) {
	printf("错误：内存分配失败。\n");
	exit(EXIT_FAILURE);
  }

  Bit_16 mask = 1 << (width - 1);

  for (; size < width;) {
	char c = (number & mask) ? '1' : '0';
	s1[size] = c;
	size++;
	mask = mask >> 1;
	if (size == capacity) { // 如果需要，增加容量
	  capacity *= 2;
	  s1 = (String) realloc(s1, capacity * sizeof(char));
	  if (s1 == NULL) {
		printf("错误：内存分配失败。\n");
		exit(EXIT_FAILURE);
	  }
	}
  }
  s1[size] = '\0';// 将最后一个字符设置为字符串的结束符
  return s1;
}

/*
 * 打印2进制
 */
void printBinary(Bit_16 number) {
  String s = NULL;
  s = binary(number);
  printf(" = %s \n", s);
  fflush(stdout);
  free(s);
}

int main(int c, char *argv[]) {
  Bit_16 b1 = 1;
  // 左移到尽头
  for (int i = 0; i < sizeof(Bit_16) * 8; ++i) {
	String s = NULL;
	Bit_16 temp = b1 << i;
	s = binary(temp);
	// P(temp<<i,"=%s\n", s);
	printf("b1 << %2d =%s \n", i, s);
	fflush(stdout);
	free(s);//用完释放

  }

  // 右移到尽头
  for (int i = 0; i < sizeof(Bit_16) * 8; ++i) {
	String s = NULL;
	Bit_16 temp = b1 >> i;
	s = binary(temp);
	// P(temp<<i,"=%s", s);

	printf("b1 >> %2d =%s \n", i, s);
	fflush(stdout);
	free(s);

  }

  P(printBinary(1));
  P(printBinary(~1 | 5 | 6));
  P(printBinary(1 | 1));
  P(printBinary(1 & 1));
  P(printBinary(1 ^ 1));
  P(printBinary(1 | 3));
  P(printBinary(RED));
  P(printBinary(GREEN));
  P(printBinary(BLUE));

  return 0;
}
