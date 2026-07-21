#include<stdio.h>

int main (void) {
  int r[200000], n, min, p = -999999999, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &r[i]);
  }

  for (i = 0; i < n; i++) {
    if (i > 0) {
      if (r[i] - min > p) {
        p = r[i] - min;
      }
      if (r[i] < min) {
        min = r[i];
      }
    } else {
    min = r[i];
    }
  }
  
  printf("%d\n", p);
  
  return 0;
}
