#include<stdio.h>
int main() {
  int n = 200000;
  int tmp;
  int max = -2000000000;
  int r[n];
  int i;

  // n?????????
  scanf("%d", &n);

  // R?????????
  for(i = 0; i < n; i++) {
    scanf("%d", &r[i]);
  }

  // ?????§???????¨????
  int min = r[0];
  for(i = 1; i < n; i++){
    tmp = r[i] - min;
    if (tmp > max) {
      max = tmp;
    }
    if (tmp < 0) {
      min = r[i];
    }
  }

  printf("%d\n", max);
  return 0;
}
