#include <stdio.h>

int main(void) {
  int n;
  int i, j;
  int r;
  int max, min;

  scanf("%d", &n);
  scanf("%d", &r);

  max = -1e9;
  min = r;
  
  for (i = 1; i < n; i++) {
    scanf("%d", &r);
    max = ((r - min) > max) ? (r - min) : max;
    min = (r < min) ? r : min;
   }

  printf("%d\n", max);
  
  return 0;
}
