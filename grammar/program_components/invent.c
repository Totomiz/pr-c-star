//
// Created by solt on 2021/9/26.
//
// 维护零件数据库，零件结构体 数量、名称、编号
//1.添加零件的名称、编号、初始现货数量，如果数量已满，则显示出错误信息
//2.给定零件编号，显示出数量信息和名称，如果零件不在数据库，显示出错误信息
//3.给定零件编号，改变现有零件数量
//4.显示出数据库中全部信息的表格，零件按照录入的顺序显示出来
//5.终止程序
//使用i(插入) s(搜索) u(更新) p(显示) q(退出)

#include <stdio.h>
#include "invert.h"
#include "readline.h"

//当前的数量
int num_part = 0;

#define println(...) printf(__VA_ARGS__); printf("\n")

void pretyPrint(struct Components components) {
    printf("\t\tID\tName\t\tRemain\n");
    printf("\t\t%d\t%s\t\t%d\n", components.numberId, components.name, components.remainNum);
    printf("\n\n");
}

int main() {
    char op;
    for (;;) {

        println("input an operation:\n");
        scanf("%c", &op);
        while (getchar() != '\n');
        switch (op) {
            case 'i':
                insert();
                break;
            case 's':
                search();
                break;
            case 'u':
                update();
                break;
            case 'p':
                display();
                break;
            case 'q':
                return 0;
            default:
                printf("\t\t[usage: i(input) s(search) u(update) p(print) q(quit)]\n");
                break;
        }
    }
    return 0;
}


void insert() {
    if (num_part > MAX_SIZE) {
        printf("current is full!\n");
        return;
    }
    int inputNum;
    printf("insert num of item:\n");
    scanf("%d", &inputNum);
    printf("your input id is :%d\n", inputNum);
    if (find_exist(inputNum) >= 0) {
        printf("Already exist!\n");
        return;
    }
    Pool[num_part].numberId = inputNum;
    printf("input name of item:\n");
    read_line(Pool[num_part].name, NAME_LENGTH);

    printf("input remain num of item:\n");
    scanf("%d", &inputNum);
    Pool[num_part].remainNum = inputNum;
    num_part++;
}

void search() {
    printf("Enter search item numID:\n");
    int id;
    scanf("%d", &id);
    int i = find_exist(id);

    if (i >= 0) {
        printf("find item:\n");
        pretyPrint(Pool[i]);
    } else {
        printf("Not find numID = %d\n", id);
    }
}


void update() {
    printf("Enter update item numID:\n");
    int id;
    scanf("%d", &id);
    int i = find_exist(id);

    if (i >= 0) {
        printf("find item:\n");
        pretyPrint(Pool[i]);
        printf("Enter update item remainNumber:\n");
        int number;
        scanf("%d", &number);
        Pool[i].remainNum = number;
        printf("After change where ID = %d item remainNumber:\n", Pool[i].numberId);
        pretyPrint(Pool[i]);
    } else {
        printf("Not find numID = %d\n", id);
    }

}

void display() {
    printf("\n\n\t\tPool table:\n\t\t________________\n");
    printf("\t\tID\tName\t\tRemain\n");
    for (int i = 0; i < num_part; ++i) {
        printf("\t\t%d\t%s\t\t%d\n", Pool[i].numberId, Pool[i].name, Pool[i].remainNum);
    }
    printf("\n\n\n");
}


int find_exist(int num) {
    for (int i = 0; i < num_part; ++i) {
        if (Pool[i].numberId == num) {
            return i;
        }
    }
    return -1;
}



