//
// Created by Administrator on 2023/3/17.
//

#include <stdio.h>

/*-----------------------结构----------------------------*/
//省略了结构标记
struct {
  int version_1;
  char name_1;
} a1;

//（结构）定义方式1：包含了结构标记
struct Part {
  int version_1;
  char name_1;
} b1,
	b2 = {0, 'n'},
	b3 = {.version_1=1000};//同时声明3个结构体变量，也可不在此处声明

struct Part b4;//声明一变量

//（结构）定义方式2：使用typedef
typedef struct {
  int version_2;
  char name_2;
} Part2;//此处使用类型定义将结构命名为类型Part2
Part2 c1, c2;//声明两个变量

/*-----------------------联合----------------------------*/
//（联合）定义方式1：包含了联合标记
union Union_1 {
  int weight;
  double name;
} d1, d2, d3;//同时声明3个联合变量，也可不在此处声明

//（联合）定义方式2：使用typedef
typedef union {
  int version_2;
  char name_2;
} Union_2;//此处使用类型定义将联合命名为类型Part2,
Union_2 e1, e2;

/*-----------------------枚举----------------------------*/
enum { ONE, TWO, THR } f1;//定义3个枚举常量 和一个变量
enum Enum_1 { FIV, SIX } f2;// 方式一：包含了枚举标记
typedef enum { TRUE = 1, FALSE = 0 } BOOL;//方式2：使用typedef类型定义

int main() {
  // b1.name_1
  f1 = ONE;
  f2 = TWO;
  Part2 a = {.name_2='c', .version_2=1};
  Part2 b = a;
  printf("%c %d", b.name_2, b3.version_1);
}