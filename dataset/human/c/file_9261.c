#include <stdio.h>
int main () {
  int n;
  int k;
  int i;
  int ans = 0;

  scanf ("%d %d", &n, &k);

  int h[n];

  for (i = 0; i < n; i++) {
    scanf ("%d", &h[i]);
  }

  for (i = 0; i < n; i++) {
    if (k <= h[i] )  ans++;
  }

  printf ("%d\n", ans);

  return 0;
}
