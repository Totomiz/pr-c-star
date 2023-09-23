//
// Created by Administrator on 2023/8/12.
//

#include <stdio.h>

void selectSort(int arr[], int n) {
  //1.重复元素-1次
  //2.设置第一个未被排序的元素
  //3.重复遍历未排序的元素
  //4.if element < currentMini
  //5 set ele as new minimum
  //6.交换minimum 和第一个unsorted position
  for (int i = 0; i < n - 1; i++) {
	int miniIndex = arr[i];
    // 在未排序部分中找到最小元素的索引
	for (int j = i + 1; j < n; j++) {
	  if (arr[j] < arr[miniIndex]) {
	    miniIndex=j;
	  }
	}
    int temp = arr[i];
    arr[i] = arr[miniIndex];
    arr[miniIndex] = temp;
  }
}

int main() {
  int arr[] = {14, -1, 3, 4, 23, 555};
  int n = sizeof(arr) / sizeof(arr[0]);

  selectSort(arr, n);

  printf("after: ");
  for (int i = 0; i < n; i++) {
	printf("%d ", arr[i]);
  }

}