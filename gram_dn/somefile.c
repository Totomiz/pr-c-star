//
// Created by solt on 2022/7/20.
//


#include "stdio.h"

int printself(char *name) {
    printf("file name %s",name);
    return 1;
}

printself(char *name);
printself("test");
printself("test");


