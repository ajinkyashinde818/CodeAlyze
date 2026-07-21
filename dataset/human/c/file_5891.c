#include <stdio.h>
#include <stdlib.h>
 
int main()
{
  int i, j, n, max, pmin, num;
  scanf("%d", &n);
  scanf("%d%d", &pmin, &num);
  max = num - pmin;
  if(pmin > num) pmin = num;
  for(i=2; i<n; i++){
    scanf("%d", &num);
    max = (max > num-pmin ? max : num-pmin);
    pmin = (pmin < num ? pmin : num); 
  }
  printf("%d\n", max);
  return 0;
}
