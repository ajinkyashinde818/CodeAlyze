/* Maximum Profit */

#include <stdio.h>

int main(void) {
  int n, x, min, maxdiff, i, diff;
  scanf("%d", &n);
  scanf("%d", &x);
  min = x;
  scanf("%d", &x);
  maxdiff = x - min;
  if(x < min) min = x;
  for(i = 2; i < n; i++) {
    scanf("%d", &x);
    diff = x - min;
    if(diff > maxdiff) maxdiff = diff;
    if(x < min) min = x;
  }

  printf("%d\n", maxdiff);

  return 0;
}
