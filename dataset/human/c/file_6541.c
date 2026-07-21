#include <stdio.h>
#define N -1000000000
 
int main()
{
  int i, n, k, max=N, min;
  scanf("%d%d", &n, &min);
  for(i = 1; i < n; i++){
    scanf("%d", &k);
    if(max < k-min) max = k - min; 
    if(k < min) min = k;
  }
  printf("%d\n", max);
  return 0;
}
