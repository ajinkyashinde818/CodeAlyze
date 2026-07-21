#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, i, j, total = 0, maxv, minv = 0;
  int *R;

  scanf("%d", &n);
  
  R = (int *)malloc(n * sizeof(int));

  for(i = 0; i < n; i++) scanf("%d", &R[i]);

  maxv = R[1] - R[0];
  minv = R[0];

  for(j = 1; j <= n - 1; j++){
    if(R[j] - minv > maxv) maxv = R[j] - minv;
    if(R[j] < minv) minv = R[j];
  }
 
  printf("%d\n", maxv);

  free(R);

  return 0;
}
