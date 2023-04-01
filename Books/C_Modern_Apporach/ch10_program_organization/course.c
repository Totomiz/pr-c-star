//
// Created by Administrator on 2022/11/3.
//
#include <stdio.h>

/*外部变量*/
int top_i = 10;

int increaseValue() {
  /*局部变量
  *有作用域
  * 函数执行期间的自动存储期限
  */
  int temp_local_value = 19;

  /*
   * 静态局部变量
   * 永久存储期限
   * 依然有作用域，为本函数内。
   */
  static int static_local_value1 = 10;
  top_i = top_i + 1;
  temp_local_value = temp_local_value + 1;
  temp_local_value = temp_local_value + 1;
  static_local_value1 = static_local_value1 + 1;
  printf("out top value : %d\n", top_i);
  printf("local temp value : %d\n", temp_local_value);
  printf("local static temp value : %d\n", static_local_value1);
}

int main() {
  for (int i = 0; i < 10; ++i) {
	printf("\t\nexec function index%d:\n", i);
	increaseValue();
  }
}

