#include <stdio.h>

int r[200000];

int calc_Max_difference(int r[], int n) {
  int rmin = r[0];
  int max = r[1] - r[0], i;

  for (i = 1; i < n; i++) {
    max = (max > r[i] - rmin ? max : r[i] - rmin);
    rmin = (rmin < r[i] ? rmin : r[i]);
  }
  return max;
}

int main(void) {
  int n, i, j, ans;

  scanf("%d", &n);

  for (i = 0; i < n; i++)
    scanf("%d", &r[i]);

  ans = calc_Max_difference(r, n);

  printf("%d\n", ans);

  return 0;
}
