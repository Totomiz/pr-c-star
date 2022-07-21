//
// Created by Administrator on 2022/7/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "Triplet.h"

Status initTriplet(Triplet *t, struct ElemType v1, struct ElemType v2, struct ElemType v3) {
  *t = malloc(3 * sizeof(struct ElemType));
  t[0] = &v1;
  t[1] = &v2;
  t[2] = &v3;
  // printf("forrr is triplet %d\n ", ((*t)->value));
  // t++;
  // printf("forrr is triplet %d\n ", ((*t)->value));
  // t + 1 = &v2;
  // t[2] = v3;
  return 0;
}

Status destroyTriplet(Triplet *t) {
  return 0;
}

Status get(Triplet *t, int i, struct ElemType e) {
  return 0;
}

int main() {
  printf("this is triplet\n");
  // printf("this is triplet %d", TRUE);
  struct ElemType e1, e2, e3;
  e1.value = 1;
  e2.value = 2;
  e3.value = 3;
  struct ElemType *a;
  initTriplet(&a, e1, e2, e3);
  printf("forrr is triplet %d\n ", ((a->value)));
  a++;
  printf("forrr is triplet %d\n ", ((a->value)));
  a++;
  printf("forrr is triplet %d\n ", ((a->value)));
  // for (int i = 0; i < 3; i++) {
	// printf("forrr is triplet %d\n ", ((a->value)));
	// a++;
  // }
}
