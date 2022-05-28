/*
  * Calculates the power of a number
  *
  * @param base: base number
  * @param power: power of the base number
  * @return base raised to the power
  */
int Power(int base, int power) {
  int result = 1;
  for (int i = 0; i < power; i++) {
    result *= base;
  }
  return result;
}