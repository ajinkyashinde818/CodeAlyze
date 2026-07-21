#include <stdio.h>

int main(void){
  int n, r[200000], i, rmin, profit;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &r[i]);
  }

  rmin = r[0];
  profit = r[1] - r[0];
  for (i = 1; i < n; i++) {
    if ( profit < r[i] - rmin){
      profit = r[i] - rmin;
    }
    if ( rmin > r[i]) {
      rmin = r[i];
    }
  }

  printf("%d\n", profit);

  return 0;
}
