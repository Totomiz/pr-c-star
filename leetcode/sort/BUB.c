//
// Created by Administrator on 2023/8/12.
//

#include <stdio.h>

#define lengthOf(array) ((int)(sizeof(array)/sizeof(array[0])))

// swapped = false
//
// for i = 1 to indexOfLastUnsortedElement-1
//
// 	if leftElement > rightElement
//
// 		swap(leftElement, rightElement)
//
// 		swapped = true; ++swapCounter
//
// while swapped

/**
 * 不断比较相邻元素
 * @param a
 * @param n
 */
void bubbleSort(int a[],int n){
  int isSwaped=0;
  do{
    isSwaped=0;
    for (int i = 1; i < n; ++i) {
      //如果左大于右交换元素
      if(a[i-1]>a[i]){
        int temp=a[i];
		a[i]=a[i-1];
		a[i-1]=temp;
        isSwaped=1;
      }
    }
  } while (isSwaped);
}

void bubbleSort2(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
	for (int j = 0; j < n - i - 1; j++) {
	  if (arr[j] > arr[j + 1]) {
		// 交换 arr[j] 和 arr[j+1]
		int temp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = temp;
	  }
	}
  }
}

int main(){
  int arr[] = {14,-1, 3, 4, 23, 555};
  int n = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, n);

  printf("after: ");
  for (int i = 0; i < n; i++) {
	printf("%d ", arr[i]);
  }

}