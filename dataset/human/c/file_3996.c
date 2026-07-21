#include <stdio.h>

int main(void) {
  int a, b, k, max, min, i;

  scanf("%d %d %d", &a, &b, &k);

  if (a > b) {
    max = a;
    min = b;
  }else {
    max = b;
    min = a;
  }

  for (i = min; i > 0; i--) {
    if (max % i == 0 && min % i == 0) {
      k--;
    }
    if (k == 0) {
      printf("%d\n", i);
      break;
    }
  }

  return 0;
}
