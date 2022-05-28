#include <stdio.h>
#include "../utils/SplitNum.h"
#include "../utils/Power.h"

int RecIntMult(int x, int y, int n);

/*
  * Recursive integer multiplication
  *
  * @param x: first number
  * @param y: second number
  * @param n: number of digits in x and y
  * @return the result of x * y
  */
int RecIntMult(int x, int y, int n) {
  // base case
  if (n == 1) {
    return x * y;
  }

  // recursive case
  else {
    int a, b, c, d;
    SplitNum(x, &a, &b);
    SplitNum(y, &c, &d);

    int ac = RecIntMult(a, c, n / 2);
    int ad = RecIntMult(a, d, n / 2);
    int bc = RecIntMult(b, c, n / 2);
    int bd = RecIntMult(b, d, n / 2);

    return Power(10, n) * ac + Power(10, n / 2) * (ad + bc) + bd;
  }
}

int main() {
  const unsigned int x = 5678;
  const unsigned int y = 1234;
  const int n = 4;
  int res;

  res = RecIntMult(x, y, n);
  printf("%d * %d = %d\n", x, y, res);

  return 0;
}
