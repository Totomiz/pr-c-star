#include <stdio.h>

typedef char* string;

int main(int con,char *args[]){
  char buff[5000];
	int count;
	char c;
	while ((c= (char)getchar())!='\n') {
	  if(c=='\0') break;
	  if(c ==' '){
		count=0;
	  }else{
		count++;
	  }
	}
	printf("%d",count);

	return 0;

}