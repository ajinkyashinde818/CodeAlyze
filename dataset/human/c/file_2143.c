#include <stdio.h>

int main() {
  long i, n;
  long x2 = 0, x5 = 0;
  scanf("%ld", &n);
  if (n % 2) { puts("0"); return 0; } // 奇数のときは0                          
  n /= 10; x5 += n;
  while (n / 5 > 0) {
    n /= 5; x5 += n;
  }
  printf("%ld\n", x5);
  return 0;
}
