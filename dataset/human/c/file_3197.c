#include <assert.h>
#include <stdio.h>
#pragma GCC optimize ("O3")

int main() {
  unsigned int k, n, i, first, last, a, max = 0;
  assert(scanf("%d %d", &k, &n) == 2);
  assert(scanf("%d", &first) == 1);
  last = first;
  for (i = 1; i < n; i++) {
    assert(scanf("%d", &a) == 1);
    a = a - last;
    last += a;
    if (max < a) {
      max = a;
    }
  }
  a = k - (last - first);
  if (max < a) {
    max = a;
  }
  printf("%d\n", k - max);
}
