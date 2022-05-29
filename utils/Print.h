#include <stdio.h>

/*
  * Prints an array
  *
  * @param name The name of the array
  * @param array The array to print
  * @param size The size of the array
  */
void Print(char* name, int* array, int size) {
  printf("%s: ", name);
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
