/*
 * Buble sort: 
 * Repeatdly compares adjacent elements and swaps them if they are in the wrong order
 *
 * After each pass, the largest elements moves to its correct position at the end of the array
 *
 * Time complexity:
 * Best: O(n)
 * Average: O(n^2)
 * Worst: O(n^2)
 *
 * Space complexity: O(1) 
 */

#include <stdio.h>

#define SIZE 5

void buble_sort(int *arr, int size){

  for (int i = 0; i < size; i++){
    for (int j = 0; j - size - 1; j++){

      if (arr[j] > arr[j + 1]){
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void print_result(int *arr, int size){

  for (int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
}

int main(void){

  int arr[SIZE] = {3,2,1,5,4};

  // before sorting:
  print_result(arr, SIZE);
  printf("\n==================\n");

  // after sorting:
  buble_sort(arr, SIZE);
  print_result(arr, SIZE);

  return 0;
}

/*
 * This algorithm is inefficient for sorting large amounts of data because it requires a large number of comparison and swap operations.
*/
