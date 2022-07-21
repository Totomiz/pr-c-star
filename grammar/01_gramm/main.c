#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../utils/base64/Base64.h"
//----------------
//int main() {
//    printf("Hello, World!\n");
//    int a = 4;
//    printf("%d",a);
//    printf(&a);
//    getchar();
//    return 0;
//}

//int main() {
//    //指针
//    int *p, i = 0;
//    p = &i;//指向i的地址
//    //反运算
//    *p = *p + 8;
//    printf("after p is= %d", *p);
//}

//----------------
/*int sum(int *a, int *b) {
    return *a + *b;
}

int sum2(int a, int b) {
    return a + b;
}

int main() {
    int a = 5;
    int b = 6;
    printf("sum=%d", sum(&a, &b));
    printf("sum=%d", sum2(a, b));
    return 0;
}*/

//--------找出N数组中的最大值和最小值--------
/*
#define N 10

void max_min(const int a[], int n, int *max, int *min);

int main() {
    int a[N], n, max, min;
    for (int i = 0; i < N; i++) {
        printf("Enter %d/%d numbers:", i, N);
        scanf("%d", &a[i]);
    }
    max_min(a, N, &max, &min);
    printf("max num is :%d\n", max);
    printf("min num is :%d\n", min);
    return 0;
}

void max_min(const int a[], int n, int *max, int *min) {
    *max = *min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] >= *max) {
            *max = a[i];
        } else if (a[i] < *min) {
            *min = a[i];
        }
    }
}
*/

//---------------
//
//int main() {
//    int a[10] = {2, 2, 2, 2, 6, 6, 7, 8, 8, 9};
//    int length = sizeof(a) / sizeof(int);
//    for (int i = 0; i < length; i++) {
//        printf("a=%d\n", a[i]);
//    }
//    int left = 1, right = 1;
//    while (right<length){
//        if (a[left] != a[right]) {
//
//            ++left;
//        }
//    }
//    int temp = 0;
//    int sum = 0;
//    for (left; left < length && right < length; left++) {
//        //如果左边==右边元素 右边指针+1再比对
//        if (a[left] != a[right]) {
//            sum++;
//            right++;
//        } else {
//            right++;
//            a[left + 1] = a[right];
//        }
//
//        if (a[left] != a[right]) {
//            if (a[left] < a[right]) {
//                right++;
//                sum++;
//            } else {
//                a[left + 1] = a[right + 1];
//                right++;
//            }
//        } else {
//            right++;
//            a[left + 1] = a[right + 1];
//            right++;
//        }
//    }
//    printf("sum == %d\n", sum);
//    printf("order");
//    for (int i = 0; i < left; i++) {
//        printf(" %d", a[i]);
//    }
//    return 0;
//}

int removeDuplicates(int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int fast = 1, slow = 1;
    while (fast < numsSize) {
        if (nums[fast] != nums[fast - 1]) {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}

//int removeDuplic(int *num, int size) {
//    if (size <= 0) {
//        return 0;
//    }
//    int fast = 1, slow = 1;
//    while (fast < size) {
//        if (num[fast] != num[fast - 1]) {
//            num[slow] = num[fast];
//            ++slow;
//        }
//        ++fast;
//    }
//    return slow;
//}
//
//int main() {
//    int a[10] = {1, 2, 2, 2, 5, 6, 7, 8, 8, 9};
//    int length = sizeof(a) / sizeof(int);
//    int sum = removeDuplicates(a, length);
//    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
//        printf("%d", a[i]);
//    }
//    printf("sum=%d", sum);
////    char *name = "zhangtong";
////    char *c = base64_encode(name);
////    char *d = "a";
////    Base64encode(d, name, strlen(name));
////    printf("\n%s", c);
////    printf("\n%s", d);
//
//
//
//}


//指针赋值运算
//int main() {
//    int i, j, *p, *q;
//    printf("star num %d\n", i);
//    printf("star num %d\n", j);
//    p = &i;
//    *p = 1;
//    q = p;
//    printf("after i=%d\n", i);
//    printf("after p=%d\n", *p);
//    printf("after q=%d\n", *q);
//
//    printf("change i \n");
//    i = 10;
//    printf("after change i \n");
//    printf("after i=%d\n", i);
//    printf("after p=%d\n", *p);
//    printf("after q=%d\n", *q);
//
//    int a;
//    a = 1;
//    *&a = 10; //
//    printf("test a= %d\n", a);
//    return 0;
//}


//指针和数组
int main() {
    int *p, *q;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 100};

    //1.使用指针遍历数组
    p = &a[0];
    for (p; p < &a[10]; ++p) {
        printf("For i = %d\n", *p);
    }

    //2.指针的加法，p+j 相当于a[i+j]
    p = &a[0];
    p = p + 3;
    printf("after p point to value %d\n", *p);

    //3.指针的减法，如果在数组中p指向a[i],p-j相当于 p指向a[i-j]
    p = p - 2;
    printf("after p point to value %d\n", *p);

    //4.指针加减指针 想当于如果p指向a[i]，q指向a[j],那么p-q 相当于 i-j
    p = &a[10];
    q = &a[3];
    int result = p - q;
    printf("after p - q to value %d\n", result);

    //5.指针的比较,可以用关系运算符和盼等运算符进行指针比较，
    // 只有两个指针指向同一数组时，关系运算符进行指针的比较才有意义，关系比较的结果依赖于在数组中的位置

    p = &a[0];
    q = &a[10];
    printf("p>q? %d\n", p > q);
    p = &a[10];
    q = &a[1];
    printf("p>q? %d\n", p > q);

    //6【指向复合常量的指针】复合字面常量是C99中的一个特征，可以用于创建没有名称的数组
    int *w = (int[]) {1, 2, 3, 4, 5, 6};

    //7【指针用于处理数组】for循环检查a[N]，实际上数组不存在a[N]的元素值，但是对于地址来说，不检查值，所以类似出现下列的遍历
    int N = 10;
    int num[10] = {1, 2, 3, 5, 67, 8, 9, 0, 10};
    int *e = &num[0];
    for (e; e < &num[N]; e++) {
        printf("num of for e=:%d\n", *e);
    }

    //8.

    return 0;
}
