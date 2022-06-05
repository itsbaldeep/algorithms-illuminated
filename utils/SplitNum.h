#include <string.h>

/*
  * Splits a number into lower and upper halves
  *
  * @param num: the number to split in string format
  * @param high: reference to the number that will contain the upper half
  * @param low: reference to the number that will contain the lower half
  * @return void
  */
void SplitNum(char* num, char* high, char* low) {
  int n = strlen(num);
  int i;
  for (i = 0; i < n / 2; i++) {
    high[i] = num[i];
  }
  high[i] = '\0';

  for (i = n / 2; i < n; i++) {
    low[i - n / 2] = num[i];
  }
  low[i - n / 2] = '\0';
}
