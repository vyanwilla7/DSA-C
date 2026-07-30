/*
 * Selection sort:
 * finds the smallest element from the unsorted portion of the data and places it in the correct position
 *
 * in each iteration, the algorithm selects the minimum element from the unsorted part of the array
 *
 * Time complexity:
 * Best: O(n^2)
 * Average: O(n^2)
 * Worst: O(n^2)
 *
 * Space complexity: O(1)
 */

#include <stdio.h>

#define SIZE 5

void selection_sort(int *arr, int size){

  for (int i = 0; i < size - 1; i++){
    int min = i;

    for (int j = i + 1; j < size; j++){
      if (arr[j] < arr[min]){
        min = j;
      }
    }

    if (min != i){
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
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
  printf("\n====================\n");

  // after sorting:
  selection_sort(arr, SIZE);
  print_result(arr, SIZE);

  return 0;
}

/*
 *This algorithm is inefficient for sorting large amounts of data because the process of searching for the minimum element is performed repeatedly.
*/
