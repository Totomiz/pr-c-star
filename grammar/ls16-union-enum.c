//
// Created by solt on 2021/9/27.
//
#include <stdio.h>

//编译器只为联合中最大的成员分配足够的内存空间，改变任意成员的值，其他成员都可能改变
union TestUnion {
    int length;
    double doubleLength;
};

// 枚举
enum Suit {
    CLUBS, BARS, SHOPS
};

enum Sui2t {
    CLUBS2 = 1, BARS2 = 2, SHOPS2 = 3
};

typedef enum {
    CLUBS3 = 1, BARS3 = 2, SHOPS3 = 3
} Suit3;

int main(int argc, char *argv[]) {
    union TestUnion anUnion = {.length=1};
    printf("union before value length %d doubleLength = %f\n", anUnion.length, anUnion.doubleLength);
    anUnion.doubleLength = 90.0;
    //可以根据输出观察到后面的int型length已经改变
    printf("union after value length %d doubleLength = %f\n", anUnion.length, anUnion.doubleLength);

    enum Suit s1;
    enum Suit2 s2;
    Suit3 s3;
}

