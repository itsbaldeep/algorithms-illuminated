/*
  * Splits a number into lower and upper halves
  *
  * @param num: the number to split
  * @param high: reference to the number that will contain the upper half
  * @param low: reference to the number that will contain the lower half 
  * @return void
  */
void SplitNum(int num, int *high, int *low) {  
  const unsigned int Base = 10;
  unsigned int divisor = Base;
  while (num / divisor > divisor) {
    divisor *= Base;
  }
  *high = num / divisor;
  *low = num % divisor;  
}
