#include <stdio.h>
int main(void) {
  int number = 9, divisor = 2, prime = number > 1;
  while (divisor * divisor <= number) {
    if (number % divisor == 0) prime = 0;
    ++divisor;
  }
  printf("%d\n", prime);
  return 0;
}
