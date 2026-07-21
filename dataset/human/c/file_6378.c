#include <stdio.h>

int main() {
  int n;
  int tmp;
  int max = -2000000000, min;

  scanf("%d", &n);
  scanf("%d", &tmp);
  min = tmp;

  int i;
  for (i = 0; i < n-1; i++) {
    scanf("%d", &tmp);
    if (max < tmp-min) {
      max = tmp-min;
    }
    if (min > tmp) {
      min = tmp;
    }
  }

  printf("%d\n", max);
  
  
  return 0;
}
