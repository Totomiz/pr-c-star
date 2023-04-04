//
// Created by Administrator on 2023/4/2.
//

#include <stdlib.h>
#include <stdio.h>

/*
 * 简易cat
 */
int main(int argc, char *argv[]) {
  if (argc < 2) {
	printf("Usage: %s file1 [file2 ...]\n", argv[0]);
	return 0;
  }

  for (int i = 1; i < argc; ++i) {
	// printf("%s\n",*(argv+i));

	FILE *fp = NULL;
	fp = fopen(argv[i], "r");
	//输出文件内容
	if (fp != NULL) {
	  char c;
	  while ((c = getc(fp)) != EOF) {
		putchar(c);
	  }
	  fclose(fp);
	  fflush(stdout);
	  printf("\n");
	}
  }

}