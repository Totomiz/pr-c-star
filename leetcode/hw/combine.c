//
// Created by Administrator on 2023/8/13.
//

#include <stdio.h>

#include <string.h>
#include <stdlib.h>


#define Pln() do { \
    printf("\n@line%d:\n",__LINE__); \
} while(0)//do while包裹多条语句，小技巧

// int main() {
//   //字符串正常定义
//   char a[] = "abc!";
//   char *s = "abc!";
//   char b[5] = "abc!";
//
//   printf("#1 %llu \n", strlen(a));
//   printf("#2 %llu \n", strlen(s));
//   printf("#3 %llu \n", strlen(b));
//
//   //遍历
//   Pln();
//   while (*s) {
// 	printf("%c", *s++);
//   }
//
//   Pln();
//   for (; *s != '\0'; s++) {
// 	printf("%c", *s);//不会输出内容，因为前面*s已经走到最后
//   }
//
//   Pln();
//   int i = 0;
//   while (a[i]) {
// 	printf("%c", a[i++]);
//   }
//
//   Pln();
//   for (int i = 0; a[i] != '\0'; i++) {
// 	printf("%c", a[i]);
//   }
//
//   Pln();
//   for (char *ptr = b; *ptr != '\0'; ptr++) {
//     printf("%c", *ptr);
//   }
//
//
//
//   return 0;
// }

#include <string.h>
#include <ctype.h>
int main() {


  setbuf(stdin, NULL);
  char a[1001] = {0};
  char b = 0;
  fgets(a, 1001, stdin);
  setbuf(stdin, NULL);
  b = getchar();

  int number = 0;
  for (int i = 0; i <= 1000; i++) {

	if(isalpha(b)&&tolower(b)==tolower(a[i])){
	  number++;
	}else{
	  if(b==a[i]){
		number++;
	  }
	}

  }
  printf("%d", number);
  return 0;
}