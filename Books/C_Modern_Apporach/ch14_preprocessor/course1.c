//
// Created by Administrator on 2023/3/14.
//

#include <stdio.h>

/*
 * 1. 简单宏
 */
#define N 10
#define D "=%d\n"

/*
 * 2.参数宏
 */
#define IS_EVEN(n) ((n)%2==0)


/*
 * 3. #运算符，用于参数宏的替换列表中，字符串化
 */
#define P_INT(x) printf(#x D,x)

/*
 * 4. ##运算符，粘合两个记号，将两个记号变为一个记号
 */
#define M_K(n) i##n
#define JOIN(x, y, z) x##y##z

int main() {
  IS_EVEN(3);
  int a = 3, b = 2;
  P_INT(a - b);
  int M_K(1) = 1, M_K(2) = 2;// 相当于声明i1,i2

  P_INT(i1 - i2);

  /*
   * 5. 预定义宏，整数常量或字符串字面量
   */
  puts(__DATE__);
  puts(__TIME__);
  printf("%d", __STDC__);
  printf("%s %d", __FILE__, __LINE__);

  /*
  * 6. 空宏参数
  */
  int M_K() = 0;
  P_INT(i);
  int JOIN(r, ,), JOIN(r, s, t), JOIN(r, , t);
  r = 1, rst = 2, rt = 3;

  /*
   * 7 参数个数可变的宏,...省略号在参数列表最后,__VA_ARGS__专用标识符，代表与...对应的参数
   *
   */
#define TEST(condition, ...) ((condition)? \
                  (printf("test passed:%s\n",#condition)): \
                  (printf(__VA_ARGS__)))

  TEST(3 > 2, "3>2 %s", "test");
  TEST(2 > 3, "output %d is not big than> %d\n", 2, 3);

  /*
   * 8. __func__标识符，与预处理器无关，每函数都可访问
   */
  printf("%s return", __func__);
#undef N
  return 0;
}