//
// Created by solt on 2021/9/22.
//
#include "stdio.h"

#define PRINT_T(n)  printf("%d \n",n)
#define MAX(x, y) ((x)>(y)?(x):(y))

//#运算符
#define dMY(expr) printf("result of # \t "#expr " = %0.2f \n",expr)

//## 运算符,沾合
#define GENRIC_MAX(type)  \
        type type##_max(type x,type y) \
        {                 \
        return x>y?x:y;   \
        }


GENRIC_MAX(float)

GENRIC_MAX(int)

//可变参数宏
#define  TEST(condition, ...) ((condition)?printf("test past %s\n",#condition):printf(__VA_ARGS__))

//C99 中__func__标识符,属于新特性，与预处理无关，实际不属于本节内容，相当于在每个函数前定义 static char args[]="function-name"
#define FUNCTION_CALLED() printf("%s function called:\n",__func__)
#define FUNCTION_RETURNED() printf("%s function returned!\n",__func__)

#define DEBUG 1


int main(int argc, char *argv[]) {
    FUNCTION_CALLED();
    PRINT_T(10);
    int a = MAX(1, 2020);
    PRINT_T(a);
    dMY(20.0f / 1);
    dMY(float_max(1100.0f, 100.0f));
    PRINT_T(int_max(1100.0f, 100.0f));
    //预定义宏 __LINE__、__FILE__\__DATE__\__TIME__\ __STDC__
    printf("this line is %d file= %s,date=%s,time=%s,STDC=%d STDC_HOSTED=%d\n", __LINE__, __FILE__, __DATE__, __TIME__,
           __STDC__, __STDC_HOSTED__);

    TEST(100 > 0, "this is pass condition");
    TEST(100 > 200, "this is un pass condition by %d > %d\n", 100, 200);

    //如 debug 为0 预处理器会删除 #if和#endif 间的这段代码
#if DEBUG
    printf("debug value of date=%s \n", __DATE__);
#endif

    //defined 运算符，应用于标识符时，如果是一个定义过的宏则返回1，否者返回0，通常与#if #endif结合使用
#if defined(DEBUG)
    printf("#if defined(DEBUG) output\n");
#endif

    //#ifdef 测试一个标识是否已经被宏定义
#ifdef DEBUG
    printf("#ifdef DEBUG output\n");
#endif

    //#ifdef 测试一个标识是否未被宏定义
#ifndef DEBUG
    printf("#ifndef DEBUG output\n");
#endif
    //#elif #else 相当于写条件语句，如条件编译macos,win,linux不同平台对应不同实现
#if DEBUG
#elif DEBUG
#else DDEBUG
#endif

    FUNCTION_RETURNED();
    return 0;
}

