//
// Created by Administrator on 2022/11/3.
//
#include <stdio.h>
#define N 10
#define M 10

int main() {
  // 用指针作为数组名
  int a[M][N] = {{1, 2, 3, 5, 6, 7, 8, 9, 10, 11},};

  printf("eg1:使用指针打印数组 \n");
  int *p;
  // 1.按在存储上的特点，当成一维数组（Q&A:合法但是可读性差，在现代编译器上的速度优势极少甚至没有）
  for (p = &a[0][0]; p < &a[M - 1][N - 1]; p++) {
	printf("%d ", *p);
  }

  printf("\neg2:使用指针更改行\n");
  // 2.使用指针更改第m行
  int *row, m = 2;
  for (row = a[m]; row < a[m] + N; row++) {
	*row = 20;
  }


  /* 数组指针vs指针数组
   * Tips:
   * 优先级：()>[]> *
   * 数组的指针：int (*y)[N]为数组指针,可理解为 int(*y)[N]是个含有N个元素的数组类型指针
   * 帮助记忆：step1.一个普通指针 int *y ，根据优先级，（*p）是一个指针，具体是个xxx的指针
   *         step2.一个数组类型指针需要后面加上[],变为数组类型指针,因为优先级关系，需要将用括号（）将 *y 包裹起来,变为int (*y)[]
   *         step3.在step2上没办法确定数组类型指针以此走多少步，所以在[]上加入步长N，最终为 int (*y)[N]
   *
   * 指针的数组：int *y[N]为指针数组,可理解为 N个指针元素的数组
   * 帮助记忆：step1.根据优先级，p[]是一个数组,是个xxx的数组
   */
  // 3.使用指针更改第n列
  printf("\neg3:使用指针更改第n列\n");
  int (*y)[N], n = 3;
  for (y = &a[0]; y < &a[M]; y++) {
	(*y)[n] = 30;
  }

  // 4.常见嵌套遍历
  for (int i = 0; i < M; ++i) {
	for (int j = 0; j < N; ++j) {
	  printf("a[%d][%d]=%d ", i, j, a[i][j]);
	}
	printf("\n");
  }
  return 0;
}

