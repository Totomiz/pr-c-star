//
// Created by Lenovot on 2023/12/28.
//
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("Welcome to the apue ,%s\n", getlogin());
    printf("My process id ,%ld\n", (long)getpid());
    return 0;
}