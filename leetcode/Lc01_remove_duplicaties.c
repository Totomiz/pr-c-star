//
// Created by solt on 2021/9/15.
//

#include <stdio.h>

#define N 4
//typedef *char Z_String

// o(1)下移动有序数组的不重复数字个数，如【1,1,2】输出 【1，2】2

int removeDuplicates(int *a, int size) {
    int slow = 1, fast = 1;
    //无需对a[0]进行插入检查，直接从a[1]
    while (fast < size) {
        if (a[fast] != a[fast - 1]) {
            a[slow] = a[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}

void printIntToArray(int *a, int size) {
    printf("result=[");
    for (int i = 0; i < size; ++i) {
        printf("%d", *(a + i));
        if (i < N - 1) {
            printf(",");
        }
    }
    printf("]\n");
}


int main() {
    int a[10], *p = &a[0]; //也可以变成一行
//    int a[10], *p;
//    p = &a[0];

    int i = 0;
    while (i < N) {
        RETRY:
        printf("scanf order num [%d/%d]\n", i, N);
        scanf("%d", (p + i));
        if (*p <= *(p + i)) {
            ++i;
        } else {
            printf("Enter a more large number,");
            goto RETRY;
        }
    }

    printf("Before:\n");
    printIntToArray(p, N);
    printf("After:\n");
    removeDuplicates(p, N);
    printIntToArray(p, N);

    printf("\t\t\tend\t\t");
}

