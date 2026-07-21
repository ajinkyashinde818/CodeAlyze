#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  long n, a[100001], count = 0, min = 1000000001, ans = 0;

  scanf("%ld", &n);

  for (long i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
    ans += abs(a[i]);
    if (a[i] < 0) count++;
    if (abs(a[i]) < min) min = abs(a[i]);
  }

  if (count % 2 == 0) {
    printf("%ld", ans);
  } else {
    printf("%ld", ans - min * 2);
  }

  return 0;
}
