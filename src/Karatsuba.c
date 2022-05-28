#include <stdio.h>
#include "../utils/SplitNum.h"
#include "../utils/Power.h"

int Karatsuba(int x, int y, int n);

/*
  * Karatsuba Multiplication
  *
  * @param x: first number
  * @param y: second number
  * @param n: number of digits in x and y
  * @return the result of x * y
  */
int Karatsuba(int x, int y, int n) {
  // base case
  if (n == 1) {
    return x * y;
  }

  // recursive case
  else {
    int a, b, c, d;
    SplitNum(x, &a, &b);
    SplitNum(y, &c, &d);

    int p = a + b;
    int q = c + d;

    int ac = Karatsuba(a, c, n / 2);
    int bd = Karatsuba(b, d, n / 2);
    int pq = Karatsuba(p, q, n / 2);

    int adbc = pq - ac - bd;

    return Power(10, n) * ac + Power(10, n / 2) * adbc + bd;
  }
}

int main() {
  const unsigned int x = 5678;
  const unsigned int y = 1234;
  const int n = 4;
  int res;

  res = Karatsuba(x, y, n);
  printf("%d * %d = %d\n", x, y, res);

  return 0;
}
