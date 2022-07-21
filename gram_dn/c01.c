//
// Created by solt on 2021/10/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include "somefile.c"

int main() {
    int i = 90;
    int *p = &i;
    printf("i addr %#x\n", &i);
    printf("i addr %d", *p);
    int time  =6;
    while (time<7){
        time--;
        sleep(2);
        printf("debug value of date=%s %d\n", __DATE__,time);
        printf("i addr %#x\n", &p);
        printf("i addr value %d\n", *p);
        printself("#include");

    }
    return 0;
}
