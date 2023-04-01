#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TOTAL_ITEM 100
struct LIMIT{
  int x1_max;
  int x2_max;
  int x3_max;
  int x4_max;
};

int rand_num(int max,int min){

  int value = rand() % max;
  if(value<=max&&value>=min){
    return value;
  }else{
    return rand_num(max,min);
  }
}



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
  while (k <= TOTAL_ITEM) {
    // srand(time(0));

	  minuend = rand_num(100,50);//被减数
	  subtrahend = rand_num(30,1); //减数

	  //
	  // if (minuend <= 20 && minuend>10 && subtrahend < 10 && subtrahend > 0 && (subtrahend+minuend)>=25) {
	  // printf("%d %d - %d = \n",k,  minuend, subtrahend);
	  // break;
	  // }
	  int operator_number = rand_num(10,1);;
	  if (operator_number == 0 || operator_number < 2) {
		continue;
	  }
	  int bool_v = (operator_number % 2 == 0) ? true : false;
	  char operator = bool_v == true ? '+' : '-';
	  int result = bool_v == true ? (minuend - subtrahend + operator_number) : (minuend - subtrahend - operator_number);
	  if (result > 0&&result<100) {
	    printf("%d - %d %c %d= \n",
	           minuend,
	           subtrahend,
	           operator,
	           operator_number,
	           result
	    );
		// if (minuend <= 18 && minuend >= 15 && subtrahend < 10 && subtrahend > 5) {
		//   // printf("%d - %d = \n",  minuend, subtrahend);
		//   // int operator_number = rand() % 10; //第三操作
		//   printf("%d - %d %c %d= \n",
		//          minuend,
		//          subtrahend,
		//          operator,
		//          operator_number,
		//          result
		//   );
		//
		// }
		//
		// if (minuend < 15 && minuend > 10 && subtrahend < 10 && subtrahend > 2) {
		//   // printf("%d - %d = \n",  minuend, subtrahend);
		//   // int operator_number = rand() % 10; //第三操作
		//
		//
		//
		//   printf("%d - %d %c %d= \n",
		//          minuend,
		//          subtrahend,
		//          operator,
		//          operator_number,
		//          result
		//   );
		//
		// }
	    k++;
	}
  }

  return 0;
}