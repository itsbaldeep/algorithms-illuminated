#include <stdio.h>
#include <stdlib.h>

#include "../utils/Print.h"

/*
  * Inversions structure
  *
  * @param inversions: number of inversions in the array
  * @param array: sorted array
  */
typedef struct Array_and_Inversions {
  int inversions;
  int* array;
} Inversions;

Inversions Sort_and_CountInv(int A[], int n);
Inversions Merge_and_CountSplitInv(int C[], int D[], int n);

/*
  * Sorts the array and calculates the number of inversions in an array
  *
  * @param A: array to be sorted
  * @param n: number of elements in A
  * @return sorted array and number of inversions in the array
  */
Inversions Sort_and_CountInv(int A[], int n) {
  Inversions res = { 0, A };

  // base case
  if (n <= 1) {
    return res;
  }

  // recursive case
  else {
    // getting the upper and lower halves of the array
    int upper[n / 2];
    int lower[n / 2];
    for (int i = 0; i < n / 2; i++) {
      upper[i] = A[i];
    }
    for (int i = n / 2; i < n; i++) {
      lower[i - n / 2] = A[i];
    }

    // recursively sorting the upper and lower halves and calculating the number of inversions
    Inversions left = Sort_and_CountInv(upper, n / 2);
    Inversions right = Sort_and_CountInv(lower, n / 2);
    Inversions split = Merge_and_CountSplitInv(left.array, right.array, n);

    free(left.array);
    free(right.array);

    res.array = split.array;
    res.inversions = left.inversions + right.inversions + split.inversions;
    return res;
  }
}

/*
  * Merges two sorted arrays into one array and counts the number of split inversions
  *
  * @param C: sorted array of upper half
  * @param D: sorted array of lower half
  * @param n: total number of elements in C and D
  * @return merged array and number of split inversions
  */
Inversions Merge_and_CountSplitInv(int C[], int D[], int n) {
  int i = 0, j = 0, k = 0;
  Inversions res = { 0, NULL };
  res.array = (int*) malloc(sizeof(int) * n);

  for (k = 0; k < n; k++) {
    if (C[i] < D[j]) {
      res.array[k] = C[i];
      i++;
    } else {
      res.array[k] = D[j];
      j++;
      res.inversions += (n / 2) - i;
    }
  }
  return res;
}

int main() {
  int arr[] = { 1, 3, 4, 2, 5, 6 };
  int n = sizeof(arr) / sizeof(int);
  Inversions res = Sort_and_CountInv(arr, n);

  printf("Number of inversions in the array: %d\n", res.inversions);
  Print("Sorted array", res.array, n);

  return 0;
}
