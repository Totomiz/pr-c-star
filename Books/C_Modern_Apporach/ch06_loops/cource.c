//
// Created by Administrator on 2022/8/29.
//

#include <stdio.h>

int main() {
  /**
   * 无线循环while(1)
   */
  long long int unLimit = 0;
  while (1) {
	printf("loop while(1) unLimit %lld\n", unLimit++);
	if (unLimit > 99) {
	  goto Label_While_Break;
	}
  }
Label_While_Break:
  printf("this is goto mark while(1) Label\n");


  for(;;){
    printf("loop for(;;) unLimit %lld\n", unLimit++);
    if (unLimit > 200) {
	  goto Label_For_Break;
    }
  }

Label_For_Break:
  printf("this is goto mark for(;;) Label\n");

  for(unLimit;unLimit>0;unLimit--){
    printf("this is for decrease, value = %lld\n",unLimit);
  }

  while (unLimit<10){
    printf("this is while(unLimit<10) loop, value = %lld\n",unLimit);
    unLimit++;
  }

  return 0;
}