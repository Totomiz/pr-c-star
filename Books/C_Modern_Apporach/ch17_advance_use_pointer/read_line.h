//
// Created by Administrator on 2023/3/18.
//

#ifndef C_STAR_BOOKS_C_MODERN_APPORACH_CH17_ADVANCE_USE_POINTER_READ_LINE_H_
#define C_STAR_BOOKS_C_MODERN_APPORACH_CH17_ADVANCE_USE_POINTER_READ_LINE_H_
typedef char *String;
String read_line();
String read_line() {
  String s1 = NULL;
  int size = 0, capacity = 1;
  s1 = (String) malloc(capacity * sizeof(char)); // 分配内存
  if (s1 == NULL) {
	printf("错误：内存分配失败。\n");
	exit(EXIT_FAILURE);
  }
  char c;
  while ((c = getchar()) != '\n') {
	s1[size++] = c;
	if (size == capacity) { // 如果需要，增加容量
	  capacity *= 2;
	  s1 = (String) realloc(s1, capacity * sizeof(char));
	  if (s1 == NULL) {
		printf("错误：内存分配失败。\n");
		exit(EXIT_FAILURE);
	  }
	}
  }
  s1[size] = '\0'; // 添加空字符
  return s1;
}
#endif //C_STAR_BOOKS_C_MODERN_APPORACH_CH17_ADVANCE_USE_POINTER_READ_LINE_H_
