//
// Created by solt on 2021/9/18.
//

#include <stdio.h>

int main(int argc,char *argv[]){
    printf("argc size =%d\n",argc);
    for (int i = 1; i < argc; i++) {
        printf("%s%s",argv[i],(i<argc)?" ":"");
    }
    printf("\n");
    return 0;
}
