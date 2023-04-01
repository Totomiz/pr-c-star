#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {     // Use current time as seed for random generator
  srand(time(0));
  // int i;
  // printf("随机生成100道20内退位减法：");
  // for (i = 0; i < 100; i++) {        //循环输出100道题目
  // int num1 = rand() % 20 + 10;// 产生1-20的随机数作为被减数num1，rand()%x+y表示[y, y+x]之间的随机整数。此处是[1, 21)之间的随机整数。
  // int num2 = rand() % (num1 - 10) + 1;     //产生11到num1-10之间的随机数作为减数num2，即保证函子大于10。此处是[11, num1)之间的随机整数。
  // printf("%d - %d = \n", num1, num2);
  // }
  int minuend, subtrahend;
  int k = 1;
  while (k <= 100) {
    // srand(time(0));

	for (int i = 0; i < 100; i++) {
	  minuend = rand() % 21 ;//被减数
	  subtrahend = rand() % 10; //减数
	  //
	  // if (minuend <= 20 && minuend>10 && subtrahend < 10 && subtrahend > 0 && (subtrahend+minuend)>=25) {
		// printf("%d %d - %d = \n",k,  minuend, subtrahend);
		// break;
	  // }

	  if (minuend <= 18 && minuend>=15 && subtrahend < 10 && subtrahend > 5) {
		printf("%d - %d = \n",  minuend, subtrahend);
	    break;
	  }

	  if (minuend <15 && minuend>10 && subtrahend < 10 && subtrahend > 2) {
		printf("%d - %d = \n",  minuend, subtrahend);
		break;
	  }
	}
	k++;
  }

  return 0;
}