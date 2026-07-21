#include <stdio.h>
int main () {
  int n, i, x = 1;
  int a[100001];
  scanf ("%d", &n);
  for (i = 1; i < n+1; ++i) {
    scanf ("%d", &a[i]);
  }
  int counter = 0;
  while (x != 2 && counter <= n) {
    x = a[x];
    counter += 1;
  }
  if (counter > n) {
    printf ("-1\n");
  } else {
    printf ("%d\n", counter);
  }
  return 0;
}
