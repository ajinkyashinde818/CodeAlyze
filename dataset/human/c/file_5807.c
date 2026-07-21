#include <stdio.h>
#define N 200000

int main(){
  int i,n,A[N],maxv,minv;;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  minv = A[0];
  maxv = A[1] - A[0];
  for(i=1;i<=n-1;i++){
    if(maxv < A[i]-minv)
      maxv = A[i]-minv;
    if(minv > A[i])
      minv = A[i];
  }
  printf("%d\n",maxv);
  return 0;
}
