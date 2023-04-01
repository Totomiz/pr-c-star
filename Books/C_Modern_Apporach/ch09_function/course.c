//
// Created by Administrator on 2022/10/31.
//
#include <stdio.h>

/**---------------------------------------------------------------------*/
/**
 * 9.1 函数定义和调用
 * define : return-type function-name ( parameters ){
 * 				    declarations
 * 				    statements
 * 		 }
 *
 */
int sum(int a, int b) {
  return a + b;
}

/**---------------------------------------------------------------------*/
/**
 * 9.2 函数声明
 * define : return-type function-name ( parameters )
 *
 */
int sum(int a, int b);

int square(int a);

/**
 * 函数声明形式参数名也可省略*
 */
int f2(int [], int);

/**---------------------------------------------------------------------*/
/**
 * 9.3.1实际参数的转换
 * @param a
 * @return
 */
int square(int a) {
  return a * a;
}

/**---------------------------------------------------------------------*/

/**
 * 9.3.2 数组型实际参数
 * 当形式参数是一维数组时，可以（通常）不说明数组长度.
 * 如何知道数组多长：C语言没有为函数提供任何简便的方法来确定传递给它的数组的长度
 * @return
 */
int f(int a[]) {
  /**
   * WRONG: not the number of element in a
   */
  int len = sizeof(a) / sizeof(a[0]);
  printf("the length of array:%d", len);
  return 0;
}

/**
 * 9.3.2，
 * 多维数组时，只能省略第一维的长度
 */
int sum_two_dimensional_array(int a[][10], int n) {
  return 0;
}
/**---------------------------------------------------------------------*/



/**
 *  * 9.3.2 数组型实际参数
 * 通常，需要把长度作为参数传递进来
	int f(int a[],int size)
 * int f(int [],int)
 */

int f2(int a[], int size) {
  return 0;
}
/**---------------------------------------------------------------------*/

/*
 * 函数原型写法：
 * int sum_array_v1(int n,int a[n])
 * int sum_array_v1(int ,int a[])
 * int sum_array_v1(int ,int [])
 * int sum_array_v1(int ,int a[*])  注意这种方式貌似在环境中没有箭头提示
 * int sum_array_v1(int n,int a[*])  注意这种方式貌似在环境中没有箭头提示
 * */
int sum_array_v1(int, int []);
/**
 * 9.3.3变长数组形式参数顺序很重要
 * @return
 */
int sum_array_v1(int n, int a[n]) {
  printf("sum_array_v1 called!");
  return 0;
}

/**
 * 9.3.4数组参数声明中使用static
 * @return
 */
int sum_v2(int [static 10], int);
int sum_v2(int a[static 10], int size) {
  return 0;
}

/**
 * 9.3.5 C99:符合字面常量
 *
 * @return
 */

void call_sum(){
  //通常 int b[]={1,2,3};
  int b[]={1,2,3};
  sum_array_v1(3,b);
  //可改为
  sum_array_v1(3,(int []){1,2,3});
  //要求值为只可读
  sum_array_v1(3,(const int []){1,2,3});

}

int main() {
  /**
   * 9.1调用
   * c99:在调用一个函数之前，必须对其先声明或定义。
   */
  int add;
  add = sum(1, 2);
  printf("sum 1+2 = %d", add);

  /**
   * 9.3.1实际参数的转换
   * 实际参数
   */
  double a = 3.0;
  printf("\nSquare:%d\n", square(a));
  int array[10] = {0, 2, 3};
  printf("\nTest of array[10] size:\n");
  f(array);

  sum_array_v1(1, array);

  return 0;
}
