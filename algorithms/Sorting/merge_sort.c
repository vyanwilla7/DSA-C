/*
 * Merge Sort
 *
 * Concept:
 * Merge Sort is a divide-and-conquer sorting algorithm.
 * The array is recursively divided into two halves until
 * each sub-array contains only one element. Since a single
 * element is already sorted, the sub-arrays are merged back
 * together by repeatedly selecting the smaller element from
 * each half, producing a fully sorted array.
 *
 * Steps:
 * 1. Divide the array into two halves.
 * 2. Recursively sort the left half.
 * 3. Recursively sort the right half.
 * 4. Merge the two sorted halves.
 *
 * Time Complexity:
 * Best: O(n log n)
 * Average: O(n log n)
 * Worst: O(n log n)
 *
 * Space Complexity: O(n)
 */

#include <stdio.h>

#define SIZE 5

void merge(int *arr, int left, int mid, int right){

  // calculate the size of the left and right sub-arrays
  int n1 = mid - left + 1; 
  int n2 = right - mid; 

  // temporary arrays used to store copies of the sub-arrays
  int L[n1], R[n2]; 

  // copying the left and right sub-arrays
  for (int i = 0; i < n1; i++){
    L[i] = arr[left + i]; 
  }

  for (int j = 0; j < n2; j++){
    R[j] = arr[mid + 1 + j]; 
  }

  int i = 0, j = 0, k = left; // k->current position in the original array
                              
  // compare elements from both sub-arrays and
  // copy the smaller one into the original array
  while (i < n1 && j < n2){
    if (L[i] <= R[j]){
      arr[k] = L[i];
      i++;

    }else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // copy the remaining elements of the array
  while (i < n1){
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2){
    arr[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int *arr, int left, int right){
  // recursively devide the array until each sub-array
  // contains only one element
  if (left < right){
        int mid = left + (right - left) / 2; // the middle index to split the array

    merge_sort(arr, left, mid); // sort the left part
    merge_sort(arr, mid + 1, right); // sort the right part

    merge(arr, left, mid, right); // combine the two sorted results
  }
}

void print_result(int *arr, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
}

int main(void){
  int arr[SIZE] = {3,2,1,5,4};

  merge_sort(arr, 0, SIZE - 1);
  print_result(arr, SIZE);
  return 0;
}
