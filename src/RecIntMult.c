#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Verbose mode (0: no, 1: yes)
#define __V 1

#include "../utils/SplitNum.h"

// Tracking total heap memory usage
long long int total_mem = 0;

void RecIntMult(char* x, char* y, char* res);

/*
  * Recursive integer multiplication
  *
  * @param x: first number in string format
  * @param y: second number in string format
  * @param res: result of multiplication in string format
  * @return: void
  */
void RecIntMult(char* x, char* y, char* res) {
  int n = strlen(x);
  // base case
  if (n == 1) {
    int x_int = atoi(x);
    int y_int = atoi(y);
    int result = x_int * y_int;

    res = itoa(result, res, 10);
    if (__V) printf("Base Case: x_int:%d * y_int:%d = res:%s (size: %d)\n", x_int, y_int, res, strlen(res));
  }

  // recursive case
  else {
    char* a = (char*) malloc(sizeof(char) * n / 2);
    char* b = (char*) malloc(sizeof(char) * n / 2);
    char* c = (char*) malloc(sizeof(char) * n / 2);
    char* d = (char*) malloc(sizeof(char) * n / 2);

    SplitNum(x, a, b);
    SplitNum(y, c, d);

    if (__V) printf("Split Num: x:%s (n: %d) divided into two: a:%s (n: %d) and b:%s (n: %d)\n", x, strlen(x), a, strlen(a), b, strlen(b));
    if (__V) printf("Split Num: y:%s (n: %d) divided into two: c:%s (n: %d) and d:%s (n: %d)\n", y, strlen(y), c, strlen(c), d, strlen(d));

    char* ac = (char*) malloc(sizeof(char) * n / 2);
    char* ad = (char*) malloc(sizeof(char) * n / 2);
    char* bc = (char*) malloc(sizeof(char) * n / 2);
    char* bd = (char*) malloc(sizeof(char) * n / 2);

    RecIntMult(a, c, ac);
    RecIntMult(a, d, ad);
    RecIntMult(b, c, bc);
    RecIntMult(b, d, bd);

    if (__V) printf("RecIntMult: a:%s (n: %d) * c:%s (n: %d) = ac:%s (n: %d)\n", a, strlen(a), c, strlen(c), ac, strlen(ac));
    if (__V) printf("RecIntMult: a:%s (n: %d) * d:%s (n: %d) = ad:%s (n: %d)\n", a, strlen(a), d, strlen(d), ad, strlen(ad));
    if (__V) printf("RecIntMult: b:%s (n: %d) * c:%s (n: %d) = bc:%s (n: %d)\n", b, strlen(b), c, strlen(c), bc, strlen(bc));
    if (__V) printf("RecIntMult: b:%s (n: %d) * d:%s (n: %d) = bd:%s (n: %d)\n", b, strlen(b), d, strlen(d), bd, strlen(bd));

    double p = pow(10, n);
    double q = pow(10, n / 2);
    if (__V) printf("Calculating Power: p: 10^%d = %.0f\n", n, p);
    if (__V) printf("Calculating Power: q: 10^%d = %.0f\n", n / 2, q);

    long long int i = p * atoi(ac);
    long long int j = q * (atoi(ad) + atoi(bc));
    long long int k = atoi(bd);
    long long int _res = i + j + k;

    printf("i:%lld + j:%lld + k:%lld = %lld\n", i, j, k, _res);

    res = itoa(_res, res, 10);
    if (__V) printf("Recursive Case: res: %s (size = %d)\n", res, strlen(res));

    long long int mem = sizeof(a) + sizeof(b) + sizeof(c) + sizeof(d) + sizeof(ac) + sizeof(ad) + sizeof(bc) + sizeof(bd);
    total_mem += mem;
    if (__V) printf("Clearing %d bytes of heap memory...\n", mem);
    free(a);
    free(b);
    free(c);
    free(d);
    free(ac);
    free(ad);
    free(bc);
    free(bd);
    if (__V) printf("Heap memory cleared.\n");
  }
}

int main() {
  // char x[] = "2989455844483932956464763283717318774932468771842801723294007020";
  // char y[] = "9343262981140700546407423727572656517778517618494497092321656547";
  char x[] = "5678";
  char y[] = "1234";

  char* res = (char*) malloc(sizeof(char) * strlen(x));

  RecIntMult(x, y, res);
  printf("x: %s\ny: %s\n", x, y);
  printf("%s\n", res);

  if (__V) printf("Clearing %d bytes of heap memory...\n", sizeof(res));
  total_mem += sizeof(res);
  free(res);
  if (__V) printf("Heap memory cleared.\n");

  if (__V) printf("Total memory used: %lld bytes\n", total_mem);
  return 0;
}
