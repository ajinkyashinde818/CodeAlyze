#include <stdio.h>
#include <stdlib.h>

int main(void) {

  long n;
  scanf("%ld", &n);
  long a[n];
  for (long i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
  }
  long sum[n];
  sum[0] = a[0];
  for (long i = 1; i < n; i++) {
    sum[i] = sum[i-1]+a[i];
  }
  long all = sum[n-1];
  long min = -1;
  for (long i = 0; i < n-1; i++) {
    if (min == -1 || labs(sum[i]*2-all) < min) {
      min = labs(sum[i]*2-all);
    }
  }
  printf("%ld\n", min);

  return 0;
}
