#include <stdio.h>

int main(void) {

  long n,m;
  scanf("%ld %ld", &n, &m);
  long a[m],b[m];
  for (long i = 0; i < m; i++) {
    scanf("%ld %ld", &a[i], &b[i]);
  }
  int from1[n],toN[n];
  for (long i = 0; i < n; i++) {
    from1[i] = 0;
    toN[i] = 0;
  }
  for (long i = 0; i < m; i++) {
    if (a[i] == 1) {
      from1[b[i]-1] = 1;
    }
    if (b[i] == 1) {
      from1[a[i]-1] = 1;
    }
    if (a[i] == n) {
      toN[b[i]-1] = 1;
    }
    if (b[i] == n) {
      toN[a[i]-1] = 1;
    }
  }
  for (long i = 1; i < n-1; i++) {
    if (from1[i] == 1 && toN[i] == 1) {
      printf("POSSIBLE\n");
      return 0;
    }
  }
  printf("IMPOSSIBLE\n");

  return 0;
}
