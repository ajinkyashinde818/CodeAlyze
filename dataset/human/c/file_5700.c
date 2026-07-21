#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int i,j,n,dmax,dmin;
  int *price;

  scanf("%d",&n);
  price = (int *)malloc(n * sizeof(int));

  for(i=0; i<n; i++) scanf("%d",&price[i]);

  dmax = price[1]-price[0];
  dmin = price[0];
  for(j=1; j<n; j++){
    dmax = (int)fmax((double)dmax,(double)(price[j] - dmin));
    dmin = (int)fmin((double)dmin,(double)price[j]);
  }

  printf("%d\n",dmax);

  free(price);

  return 0;
}
