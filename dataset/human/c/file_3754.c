#include <stdio.h>

long GCD(long a, long b){
  long dividend, divisor;
  if (a >= b) {
    dividend = a;
    divisor = b;
  } else {
    dividend = b;
    divisor = a;
  }
  long remainder;
  while (1) {
    if (divisor == 1) {
      return 1;
    }
    remainder = dividend % divisor;
    if (remainder == 0) {
      break;
    } else {
      dividend = divisor;
      divisor = remainder;
    }
  }
  return divisor;
}

int main(void){

  long a,b;
  scanf("%ld %ld", &a, &b);

  long gcd_ = GCD(a,b);
  long answer = a*b;
  answer /= gcd_;

  printf("%ld\n", answer);

  return 0;
}
