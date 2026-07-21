#include <stdio.h>
#include <stdlib.h>
int main(){
  int i,j,n;
  int maxv,minv;
 
  scanf("%d",&n);
  if(n < 2 || 200000 < n){
    exit(1);
  }
  int R[n];
 
  for(i = 0; i< n; i++){
    scanf("%d",&R[i]);
    if(R[i] < 1 || 10000000000 < R[i]){
      exit(1);
    }
  }
  minv = R[0];
  maxv = R[1]-R[0];
  for(j = 1; j <= n-1; j++){
    if(maxv <= R[j]-minv){
      maxv = R[j]-minv;
    }
    if(R[j] < minv){
      minv = R[j];
    }
  }
  printf("%d\n",maxv);
  return 0;
}
