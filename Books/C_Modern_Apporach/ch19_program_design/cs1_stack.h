//
// Created by Administrator on 2023/3/19.
//

#ifndef C_STAR_BOOKS_C_MODERN_APPORACH_CH19_PROGRAM_DESIGN_CS1_STACK_H_
#define C_STAR_BOOKS_C_MODERN_APPORACH_CH19_PROGRAM_DESIGN_CS1_STACK_H_
#include <stdbool.h>

/*
 * 1.不完整类型：描述了对象，但缺少定义对象大小的信息
 * 2.下面类型定义表明：类型Stack的变量 是指向 标记为stack_type的结构 的指针
 * */
typedef struct stack_type *Stack;
typedef int ITEM;

// 根据宏定义来确定函数原型的类型
#ifdef STACK_WITH_SIZE_PARAM
Stack create(int size);
#else
Stack create(void);
#endif

void destroy(Stack s);
void make_empty(Stack s);//为在方法传参时用指针，比传递值更有效相当于void make_empty(struct stack_type *s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, ITEM item);
ITEM pop(Stack s);
void toString(Stack s);
#endif //C_STAR_BOOKS_C_MODERN_APPORACH_CH19_PROGRAM_DESIGN_CS1_STACK_H_
