//
// Created by Administrator on 2022/8/30.
//

#include <stdio.h>

#define N 10

/**
 * 带参数宏
 */
#define SIZE(array) ((int)(sizeof(array)/ sizeof(array[0])))

int main() {
  /**
   * 1.一维数组
   * 定义：int a[N];
   * 初始化：int a[10]={1,2,3,4}
   * 		或者 a[10]={0}
   * c99: int a[10]={[1]=9,[5]=7};指定位置初始化
   */
  unsigned int one_dimensional_array[10]={12,34,1,};
  /*sizeof返回类型为size_t为无符号类型,不强转可能会有警告，因为变量i为有符号整数*/
  for (int i = 0; i < (int )(sizeof(one_dimensional_array)/ sizeof(one_dimensional_array[0])) ;++i) {
    printf("index of One dimensional[%d]:%d\n",i,one_dimensional_array[i]);
  }

  /*
   * 使用宏定义替换长度计算
   */
  for (int i = 0; i < SIZE(one_dimensional_array); ++i) {
    printf("\tindex of One dimensional[%d]:%d\n",i,one_dimensional_array[i]);
  }

  return 0;
}