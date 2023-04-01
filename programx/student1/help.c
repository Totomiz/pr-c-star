//
// Created by Administrator on 2023/3/28.
//

#include "help.h"
#include <time.h>

srand(time(0));
inline int rand_num(int max, int min) {

  int value = rand() % max;
  if (value <= max && value >= min) {
	return value;
  } else {
	return rand_num(max, min);
  }
}