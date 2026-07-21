#include <stdio.h>

int main(){
  int A[2000000],i,n,maxv,minv;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  maxv=A[1]-A[0];
  minv=A[0];
  for(i=1;i<n;i++){
    if(maxv<A[i]-minv)
      maxv=A[i]-minv;
    if(minv>A[i])minv=A[i];
  }
  printf("%d\n",maxv);
  return 0;
}
