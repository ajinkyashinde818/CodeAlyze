#include <stdio.h>
#include <limits.h>

int main(void) {
  int n;
  int R;
  int i;
  int min;
  int diff_max = INT_MIN;
  
  scanf("%d", &n);

  scanf("%d", &min);
  for (i=1; i<n; i++) {
    scanf("%d", &R);

    if (diff_max < R-min) 
      diff_max = R-min;

    if (R<min) 
      min = R;
  }

  printf("%d\n", diff_max);

  return 0;
}
