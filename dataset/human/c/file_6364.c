#include <stdio.h>
#define N 200000

int main(){

  int i,j,n,minv,maxv;
  int A[N];

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  } 

  minv = A[0];
  maxv = A[1]-A[0];

  for(j=1; j<=n-1; j++){
    if(maxv < A[j]-minv)
      maxv = A[j]-minv;
    if(minv > A[j])
      minv = A[j];
  }
    printf("%d\n",maxv);
  return 0;
}
