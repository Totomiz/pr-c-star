//
// Created by solt on 2021/9/26.
//
#include <stdio.h>
#include <ctype.h>
#include "readline.h"

void read_line(char name[], int length) {
    char c;
    int i = 0;
    while (isspace(c = getchar()));
    while (c != '\n' && c != EOF) {
        if (i < length) {
            name[i++] = c;
        }
        c = getchar();
    }
}