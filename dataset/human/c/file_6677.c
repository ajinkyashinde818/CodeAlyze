#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
  int n, i, j;
  int *R;
  int max = INT_MIN;
  int min;

  scanf("%d", &n);

  R = (int *)malloc(sizeof(int) * n);

  for (i = 0; i < n; i++) scanf("%d", &R[i]);

  min = R[0];
  for (i = 1; i < n; i++) {
    if (max < R[i] - min) max = R[i] - min;
    if (min > R[i]) min = R[i];
  }

  printf("%d\n", max);

  free(R);
  
  return 0;
}
