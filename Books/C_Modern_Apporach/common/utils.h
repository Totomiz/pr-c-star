//
// Created by Administrator on 2023/4/3.
//

#ifndef C_MODERN_APPROACH_BOOKS_C_MODERN_APPORACH_COMMON_UTILS_H_
#define C_MODERN_APPROACH_BOOKS_C_MODERN_APPORACH_COMMON_UTILS_H_
typedef char *CString;

#define println(...) do { \
    printf(__VA_ARGS__); \
    printf("\n");\
} while(0)//do while包裹多条语句，小技巧

CString read_line();

#endif //C_MODERN_APPROACH_BOOKS_C_MODERN_APPORACH_COMMON_UTILS_H_
