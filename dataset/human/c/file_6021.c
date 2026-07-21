#include <stdio.h>
#include <stdlib.h>
int main(){
  int *R,j,n,minv,maxv;

  scanf("%d",&n);
  R = (int *)malloc(n * sizeof(int));

  for(j = 0 ; j < n ; j++) scanf("%d",&R[j]);
  
  minv = R[0];
  maxv = R[1] - R[0];
  
  for(j = 1 ; j <= n - 1 ; j++){
    if(maxv < R[j] - minv) maxv = R[j] -minv;   
    if(minv > R[j]) minv = R[j]; }

    printf("%d\n",maxv);

    free(R);
    
    return 0;
}
