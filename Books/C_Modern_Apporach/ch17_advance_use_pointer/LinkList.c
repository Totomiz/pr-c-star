//
// Created by Administrator on 2023/3/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"
#include <string.h>
#include <ctype.h>

typedef struct node {
  struct node *next;
  int value;//data
  int index;
} Node;

int idx = 0;
Node *add(Node *list, int value) {
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL) {
	printf("malloc failed!\n");
	exit(EXIT_FAILURE);
  }
  new_node->next = list;
  new_node->value = value;
  new_node->index = idx++;

  return new_node;
};

Node *delete(Node *list, int value) {
  Node *current, *pre;
  current = list;
  pre = NULL;
  for (; current != NULL && current->value != value;) {
	pre = current;
	current = current->next;
  }
  if (current == NULL) {
	return list;//没找到value
  }
  if (pre == NULL) {//第一个节点就是
	list = list->next;
  } else {//此处找到的中间节点
	pre->next = current->next;
	free(current);
  }
  return list;
};

Node *find(Node *list, int value) {
  Node *p = NULL;
  for (p = list; p != NULL; p = p->next) {
	if (p->value == value) {
	  printf("\tfind: index %d value=%d addr=%p\n", p->index, p->value, p);
	  return p;
	}
  }
  printf("\tNot find !\n");
  return NULL;
};

void display(Node *list) {
  Node *current;
  for (current = list; current != NULL; current = current->next) {
	printf("\r\tindex=%d value=%-10.d addr=%p\n", current->index, current->value, current);
  }
}

int main() {
  Node *first = malloc(sizeof(Node));
  first->value = 0;
  first->next = NULL;
  char op[10];

  for (;;) {
	printf("choose action:\n");
	printf("\tInsert(I)\tdelete(D)\tfind(F)\tdisplay(P)\tquit(Q)\n");
	printf("input an operation:\n");
    if(fgets(op,100,stdin)==NULL){
      // 读取输入失败，退出循环
      break;
    }
	switch (toupper(op[0])) {
	  case 'I': {
	    while (1) {
		  char input[100];
		  printf("input number:");
		  if (!fgets(input, 100, stdin)) {
		    // 读取输入失败，退出循环
		    break;
		  }
		  errno = 0;
		  char *endptr;
		  long num = strtol(input, &endptr, 10);
		  if (errno || endptr == input || *endptr != '\n') {
		    // 转换失败，提示用户重新输入
		    printf("Invalid input, please input a number.\n");
		    continue;
		  }
		  if (num < INT_MIN || num > INT_MAX) {
		    // 用户输入数字超过了int类型的取值范围，提示用户重新输入
		    printf("The number is out of range, please input again.\n");
		    continue;
		  }
		  int number = (int)num;
		  first = add(first, number);
		  display(first);
		  if (number == 0) {
		    break;
		  }
	    }

	    break;
	  }
	  case 'D': {

	    while (1) {
		  char input[100];
		  int number;
		  printf("input number(0 quit):");
		  fgets(input, 100, stdin);
		  if (sscanf(input, "%d", &number) != 1) {
		    // 用户输入不是数字，提示用户重新输入
		    printf("Invalid input, please input a number.\n");
		    continue;
		  }
		  if (number < INT_MIN || number > INT_MAX) {
		    // 用户输入数字超过了int类型的取值范围，提示用户重新输入
		    printf("The number is out of range, please input again.\n");
		    continue;
		  }
		  if (number == 0) {
		    break;
		  }
	      delete(first, number);
	      display(first);
	    }
		break;
	  }
	  case 'F': {
		printf("input number:");
		int number;
		scanf("%i", &number);
		find(first, number);
		break;
	  }
	  case 'P': display(first);
		break;
	  case 'Q': return 0;
	  default:break;
	}

  }
  return 0;
}
