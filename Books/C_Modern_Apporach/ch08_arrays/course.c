//
// Created by Administrator on 2022/8/30.
//

#include <stdio.h>

#define N 10
#define M 11

/**
 * 带参数宏
 */
#define SIZE(array) ((int)(sizeof(array)/ sizeof(array[0])))

int main() {
  int a[]={0};
  int ap[10]={};
  /**
   * 1.一维数组
   * 定义：int a[N];
   * 初始化：int a[10]={1,2,3,4}
   * 		或者 a[10]={0}
   * c99: int a[10]={[1]=9,[5]=7};指定位置初始化
   * 同时存在 int a[]={1,2,9,4,[0]=5,8} 输出 {5,8,9,4}
   */
  unsigned int one_dimensional_array[10] = {12, 34, 1,};
  /*sizeof返回类型为size_t为无符号类型,不强转可能会有警告，因为变量i为有符号整数*/
  for (int i = 0; i < (int) (sizeof(one_dimensional_array) / sizeof(one_dimensional_array[0])); ++i) {
	printf("index of One dimensional[%d]:%d\n", i, one_dimensional_array[i]);
  }

  /*
   * 使用宏定义替换长度计算
   */
  for (int i = 0; i < SIZE(one_dimensional_array); ++i) {
	printf("\tindex of One dimensional[%d]:%d\n", i, one_dimensional_array[i]);
  }

  /**
   * 8.2.1多维数组
   * 定义：int a[M][N];
   * 初始化：int a[M][N] = {{1,2,3},{1,23,4},...};可不全列出
   * C99(可指定位置初始化): int a[2][2] = { [0][1]=1,[1][1]=2};
   */

  int multi_dimensional_array[M][N] = {{1, 2, 3}, {4, 5, 6}};
  printf("multi dimensional array [%dx%d] value:\n", M, N);
  for (int i = 0; i < M; ++i) {
    printf("\n");
	for (int j = 0; j < N; ++j) {
	  printf("index[%d][%d] = %d  ", i, j, multi_dimensional_array[i][j]);
	}
  }

  /**
   * 8.2.2 常量数组 constant arrays
   * 定义：在数组前面加 const
   */
  const char hex_chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
  for (int i = 0; i < SIZE(hex_chars); ++i) {
	printf("constant hex char [%d] = %c\n", i, hex_chars[i]);
  }

  /**
   ** 8.3 c99中的变长数组VLA
   * 变长长度不一定用变量来指定，任意表达式（可以包含运算）：
   * int a[3*i+5];
   * int b[j+k];
   * 变长数组主要限制是没有静态存储期限,没有初化式
   */
  int vla[3 + M];
  printf("\tVLA before:\n");
  for (int i = 0; i < SIZE(vla); ++i) {
	printf("\tVLA[%d]:%d\n", i, vla[i]);
  }
  for (int i = 0; i < SIZE(vla); ++i) {
	scanf("%d", &vla[i]);
  }
  printf("\tVLA after:\n");
  for (int i = 0; i < SIZE(vla); ++i) {
	printf("\tVLA[%d]:%d\n", i, vla[i]);
  }
  return 0;
}