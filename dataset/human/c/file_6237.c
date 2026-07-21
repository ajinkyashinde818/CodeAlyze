#include <stdio.h>

int main() {
  int n, i, j;
  int r[200000];
  int max, min;

  scanf("%d", &n);

  for (i = 0; i < n; i++)
    scanf("%d", &r[i]);

  max = r[1] - r[0];
  min = r[0];
  for (i = 1; i < n; i++) {
    if((r[i] - min) > max) max = r[i] - min;

    if(r[i] < min) min = r[i];
  }

  printf("%d\n", max);

  return 0;
  
}
