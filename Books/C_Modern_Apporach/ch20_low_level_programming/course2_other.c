#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * 1.定义机器依赖的类型
 *
 */
typedef unsigned char BYTE;

// void viewMemory(){
//   printf()
// }
int main(){
  printf("BYTE = %llu", sizeof(unsigned char ));
  printf("SHORT = %llu", sizeof(short ));
  /*
   * 2.用指针作为地址使用
   */
  BYTE *p;
  p=(BYTE *) 100;


  /*
   * 3. viewMemory
   */
  printf("address of main function: %x\n",(unsigned int )main);

  unsigned int addr;
  int i,n;
  printf("\nEnter a (hex) address:");
  setbuf(stdin,NULL);
  scanf("%x",&addr);
  printf("\nEnter number of bytes to view :");
  setbuf(stdin,NULL);
  scanf("%d",&n);
  printf("\n");
  printf("Address                   Bytes          Characters\n");
  printf("-------  ------------------------------  ----------\n");
  p=(BYTE*) addr;
  for (; n >0;n-=10)  {
    printf("%8X  ",(unsigned int )p);
    for (i = 0; i < 10 && i < n;i++) {
      printf("%.2X ",*(p+i));
    }
    for (;i<10;i++){
      printf("  ");
    }
    printf("  ");
    for (i=0;i<10&&i<n;i++){
      BYTE ch=*(p+i);
      if(!isprint(ch)){
        ch='.';
      }
      printf("%c",ch);
    }
    printf("\n");
    p+=10;
  }
  return 0;
}
