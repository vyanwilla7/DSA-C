/*
 * Selection sort:
 * takes an element from the unsorted portion of the data and inserts it into the correct position within the sorted portion
 *
 * this algorithm operates on the same principle as someone sorting cards in their hand
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

void insertion_sort(int *arr, int size){
  
  for (int i = 1; i < size; i++){

    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] >= key){
        
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
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
  insertion_sort(arr, SIZE);
  print_result(arr, SIZE);

  return 0;
}

/*
 *This algorithm has an average time complexity of O(n^2), making it less efficient for large datasets. However, Insertion Sort is quite efficient for small datasets or data that is nearly sorted.
*/
