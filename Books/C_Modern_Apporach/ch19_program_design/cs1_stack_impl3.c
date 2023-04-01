//
// Created by Administrator on 2023/3/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "cs1_stack.h"

typedef struct node {
  ITEM data;
  struct node *next;
} Node;

/**
 * 用链表实现
 */
struct stack_type {
  Node *top;
};

static void terminate(const char *msg) {
  printf("%s\n", msg);
  exit(EXIT_FAILURE);
}

Stack create(void) {
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL)
	terminate("Error in create");
  s->top = NULL;
  return s;
}

void destroy(Stack s) {
  make_empty(s);
  free(s);
}

void make_empty(Stack s) {
  while (!is_empty(s))
	pop(s);
}

bool is_empty(Stack s) {
  return s->top == NULL;
}

bool is_full(Stack s) {
  return false;
}

void push(Stack s, ITEM item) {
  if (is_full(s))
	terminate("Error in push:stack full");
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL)
	terminate("No space left!");

  new_node->data = item;
  new_node->next = s->top;
  s->top = new_node;

}

ITEM pop(Stack s) {
  if (is_empty(s))
	terminate("Error in pop:stack is empty");
  Node *old = s->top;
  ITEM old_data = old->data;
  s->top = old->next;
  free(old);
  return old_data;
}

void toString(Stack s) {
  Node *current = s->top;
  while (current != NULL) {
	printf(" item= %d\n", current->data);
	current = current->next;
  }
}
#define M(n) i##n=n
int main() {
  Stack s = create();

  for (int i = 0; i < 10; ++i) {
    ITEM M(i);
    push(s,M(i));
  }
  toString(s);
  return 0;
}