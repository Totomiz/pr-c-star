//
// Created by solt on 2021/9/18.
//

#include <stdio.h>

//本程序 主要为打印附带参数 如生成gcc -o j command-line-arg.c,运行./j -version ./j -help
int main(int argc,char *argv[]){
    printf("argc size =%d\n",argc);
    for (int i = 1; i < argc; i++) {
        printf("%s%s",argv[i],(i<argc)?" ":"");
    }
    printf("\n");
    return 0;
}
