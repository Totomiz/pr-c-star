//
// Created by solt on 2021/9/26.
//

#ifndef C_STAR_INVERT_H
#define C_STAR_INVERT_H

#endif //C_STAR_INVERT_H
#define MAX_SIZE 100
#define NAME_LENGTH 25
struct Components {
    int numberId;//编号
    char name[NAME_LENGTH + 1];//名称
    int remainNum;//剩余数量
} Pool[MAX_SIZE];

int find_exist(int num);

void insert();

void search();

void update();

void display();

void quit();
