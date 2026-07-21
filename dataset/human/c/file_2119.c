#include <stdio.h>

int main(void) {

  long n;
  scanf("%ld", &n);
  if (n%2 == 1) {
    printf("0\n");
    return 0;
  }
  long answer = 0;
  long base = 2;
  long plus;
  while (1) {
    base *= 5;
    plus = n/base;
    if (plus == 0) {
      break;
    }
    answer += plus;
  }
  printf("%ld\n", answer);

  return 0;
}
