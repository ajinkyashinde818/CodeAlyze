#include <stdio.h>
#include <stdlib.h>

int main(){
  int i, n, *R, max, min;

  scanf("%d",&n);

  R = malloc(sizeof(int)*n);

  for(i = 0; i < n; i++) scanf("%d",&R[i]);

  min = R[0];
  max = R[1] - R[0];
  
  for(i = 1; i < n; i++){
    if(max < (R[i] - min)) max = (R[i] - min);

    if(min > R[i]) min = R[i];
  }

  printf("%d\n",max);

  free(R);

  return 0;
}
