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




int main(int argc, char *argv[]) {
    PRINT_T(10);
    int a = MAX(1, 2020);
    PRINT_T(a);
    dMY(20.0f / 1);
    dMY(float_max(1100.0f, 100.0f));
    PRINT_T(int_max(1100.0f, 100.0f));
    //预定义宏 __LINE__、__FILE__\__DATE__\__TIME__\ __STDC__
    printf("this line is %d file= %s,date=%s,time=%s,STDC=%d\n", __LINE__, __FILE__, __DATE__, __TIME__, __STDC__);
    return 0;
}

