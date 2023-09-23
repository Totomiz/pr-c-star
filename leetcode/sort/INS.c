//
// Created by Administrator on 2023/8/12.
//

#include <stdio.h>


#define SIZE(array) ((int)(sizeof(array)/ sizeof(array[0])))



/**
 * 插入排序
 * @param arr
 * @param n
 */
void insertionSort(int arr[], int n) {
  //从第一个元素开始计算
  for (int i = 1; i < n; i++) {
	int key = arr[i];
	int j = i - 1;
	while (j >= 0 && arr[j] > key) {
	  arr[j + 1] = arr[j];
	  j--;
	}
	arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {14, 3, 4, 23, 555};
  int n = sizeof(arr) / sizeof(arr[0]);

  insertionSort(arr, n);

  printf("after: ");
  for (int i = 0; i < n; i++) {
	printf("%d ", arr[i]);
  }

  return 0;
}