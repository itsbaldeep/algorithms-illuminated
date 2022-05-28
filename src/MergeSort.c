#include <stdio.h>
#include <stdlib.h>

int* MergeSort(int arr[], int n);
int* Merge(int upper[], int lower[], int n);

/*
  * Merge Sort Algorithm
  *
  * @param arr: array to be sorted
  * @param n: number of elements in arr
  * @return array sorted in ascending order
  */
int* MergeSort(int arr[], int n) {
  // base case
  if (n == 1) {
    return arr;
  }

  // recursive case
  else {
    // getting upper and lower half of the array
    int upper[n / 2];
    int lower[n / 2];
    for (int i = 0; i < n / 2; i++) {
      upper[i] = arr[i];
    }
    for (int i = n / 2; i < n; i++) {
      lower[i - n / 2] = arr[i];
    }

    // recursively sorting the upper and lower half
    int* upper_sorted = MergeSort(upper, n / 2);
    int* lower_sorted = MergeSort(lower, n / 2);

    // merging the upper and lower sorted halves
    return Merge(upper_sorted, lower_sorted, n);
  }
}

/*
  * Merge subroutine
  *
  * @param upper: upper half of array
  * @param lower: lower half of array
  * @param n: number of elements in upper and lower
  * @return array sorted in ascending order
  */
int* Merge(int upper[], int lower[], int n) {
  int i = 0, j = 0, k = 0;
  int* sorted = (int*) malloc(n * sizeof(int));

  // merging the upper and lower halves
  for (k = 0; k < n; k++) {
    if (upper[i] < lower[j]) {
      sorted[k] = upper[i];
      i++;
    } else {
      sorted[k] = lower[j];
      j++;
    }
  }
  return sorted;
}

int main() {
  int arr[] = {5, 4, 1, 8, 7, 2, 6, 3};
  int n = sizeof(arr) / sizeof(int);

  int* res = MergeSort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", res[i]);
  }

}
