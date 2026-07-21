#include <stdio.h>
#define MAX 200000

int max(int a, int b) {
  return (a > b) ? a : b;
}

int min(int a, int b) {
  return (a < b) ? a : b;
}

int main() {
  int i, n, R[MAX], maxv, minv;

  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &R[i]);

  maxv = -1e+9;
  minv = R[0];
  for (i = 1; i < n; i++) {
    maxv = max(maxv, R[i] - minv);
    minv = min(minv, R[i]);
  }

  printf("%d\n", maxv);

  return 0;
}
