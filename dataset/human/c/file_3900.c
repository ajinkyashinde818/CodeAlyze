#include <stdio.h>

int main(void) {
  int a, b, k;
  int i, n;
  int ary[100];
  
  scanf("%d%d%d", &a, &b, &k);
  for (i = 1, n = 0; i <= a && i <= b; i++) {
    if (a % i  == 0 && b % i == 0) {
      ary[n] = i;
      n++;
    }
  }
  printf("%d\n", ary[n - k]);
  return 0;
}
