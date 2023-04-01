//
// Created by Administrator on 2023/3/14.
//

#include <stdio.h>
#define INT_MAX 10000


#if INT_MAX>10000
#error "Max int is 10000!"
#endif
#line 10
#line 2 __FILE__

#pragma data(Heap==>2000)


int main(){
  printf("其他指令");
  return 0;
}