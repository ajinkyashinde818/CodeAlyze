#include <stdio.h>

int main(void) {
  int i, n, a[10000000], maxv = -999999999, minv = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  minv = a[0];
  for (i = 1; i < n; i++) {
    if (maxv < (a[i] - minv)) {
      maxv = a[i] - minv;
    }
    if (minv > a[i]) {
      minv = a[i];
    }
  }

  printf("%d\n", maxv);
}
