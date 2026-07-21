#include <stdio.h>

int main() {
  long a, b, tmp, sosu, tmp_b;
  scanf("%ld %ld", &a, &b);

  if (a > b) {
    tmp = a;
    a = b;
    b = tmp;
  }

  tmp_b = b;
  while(1) {
    if (b % a == 0) {
      break;
    }
    b += tmp_b;
  }

  printf("%ld\n", b);

  return 0;
}
