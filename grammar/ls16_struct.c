//
// Created by solt on 2021/9/24.
//

#include <stdio.h>


//直接定义名字
struct PointZT {
    int x;
    int y;
    char *name;
} A = {.name="aaab", .x=1, .y=2}, B = {.name="BBB", .x=1, .y=5};


// typedef 方式定义的方式名字放在末尾，同理typedef type name;
typedef struct {
    int w;
    int h;
    char *name;
} Rect;

//struct做为参数
void area(struct PointZT pointZt) {
    printf("this area point x=%d y = %d\n", pointZt.x, pointZt.y);
}
//struct作为返回值

struct PointZT funcGenPoint(int x, int y, char *name) {
    struct PointZT a = {.x=x, .y=y, .name=name};
    return a;
}

#define PintPoint(expr, x, y) printf(#expr " of value x = %d y=%d",x,y )

int main() {
//    A.name="AAA";
//    A.x=100;
//    A.y=2000;
    printf("name of a %s", A.name);
    printf("sum of a = %d", A.x + A.y);
    printf("\n");
    printf("name of b %s", B.name);
    printf("sum of b = %d", B.x + B.y);
    //使用typedef方式声明struct的局部变量定义,前面不需加struct关键字
    Rect a = {.w=200, .h=100, .name="rectA"};
    Rect b = {.w=200, .h=100, .name="rectA"};
    struct PointZT pointZtA = {.name="aac", .x=1, .y=2};
    printf("sum of RectA = %d", a.w + a.h);
    printf("sum of pointZtA = %d", pointZtA.x + pointZtA.y);
    area(pointZtA);
    struct PointZT genPoint = funcGenPoint(10, 40, "genPoint");
    PintPoint(funcGenPoint(10, 40, "genPoint"), genPoint.x, genPoint.y);
}
