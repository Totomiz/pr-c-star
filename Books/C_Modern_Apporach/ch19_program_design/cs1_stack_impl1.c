//
// Created by Administrator on 2023/3/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "cs1_stack.h"
#define STACK_SIZE 100
/**
 * 用定长数组实现
 */

struct stack_type {
  ITEM contents[STACK_SIZE];
  int top;
};

static void terminate(const char *msg) {
  printf("%s\n", msg);
  exit(EXIT_FAILURE);
}

Stack create(void) {
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL)
	terminate("Error in create");
  s->top = 0;
  return s;
}
void destroy(Stack s) {
  free(s);
}
void make_empty(Stack s) {
  s->top = 0;
}
bool is_empty(Stack s) {
  return s->top == 0;
}
bool is_full(Stack s) {
  return s->top == STACK_SIZE;
}
void push(Stack s, ITEM item) {
  if (is_full(s))
	terminate("Error in push:stack full");
  s->contents[s->top++] = item;
}

ITEM pop(Stack s) {
  if (is_empty(s))
	terminate("Error in pop:stack is empty");
  // s->contents[--s->top] 怎么分析
  // 1. s->top：获取指针s所指向的Stack结构体中的 top 成员变量（即当前栈顶元素在 contents 数组中的索引）。
  // 2. --s->top：将 top 减 1，并返回新值。由于前缀 -- 运算符优先级高于 -> 运算符，因此该表达式等价于 (--(s->top))。
  // 3. s->contents[--s->top]：使用上一步得到的新值作为数组下标来访问 Stack 结构体中 contents 数组对应位置上的元素，并将其返回。
  return s->contents[--s->top];
}

void toString(Stack s) {
  for (int i = 0; i < s->top; ++i) {
	printf(" item= %d\n", s->contents[i]);
  }
}

int main() {
  struct stack_type * stack_type = malloc(sizeof (struct stack_type));
  stack_type->top=0;

  Stack s = create();
  ITEM item = 10;
  push(stack_type, item);
  printf("before %x",(unsigned int)main);
  toString(stack_type);
  pop(stack_type);
  printf("after\n");
  toString(stack_type);
  printf("==================\n");
  toString(stack_type);
  push(s, item);
  push(s, item);
  push(s, item);
  push(s, item);
  toString(s);
  push(s, 20);
  toString(s);
  make_empty(s);
  toString(s);
  return 0;
}
