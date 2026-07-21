#include<stdio.h>

int main(){
  int n, t, r, min = 1000000000, pvmin, prof = -999999999;
  pvmin = min;

  scanf("%d", &n);
  for (t = 0; t < n; t++) {
    scanf("%d", &r);
    if (r < min) {
      pvmin = r;
    }
    if (t > 0 && r - min > prof) {
      prof = r - min;
    }
    min = pvmin;
  }
  printf("%d\n", prof);

  return 0;
}
