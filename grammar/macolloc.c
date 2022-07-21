//
// Created by solt on 2021/10/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *p=malloc(sizeof(char));
    *p='a';
    strcpy(p,"abcdefghijklmn");

//    while (p!=NULL){
//
//    }

    printf("a %c\n",*(p+5));
    printf("int size %lu 字节\n", sizeof(int));
    printf("char size %lu 字节\n", sizeof(float ));
    free(p);
    // system("ls");
}
