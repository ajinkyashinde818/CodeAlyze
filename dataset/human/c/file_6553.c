#include <stdio.h>
#define N 200000
int main(){
  int i=0,minv=0,R[N],j=0,n=0,maxv=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }
  minv=R[0];
  maxv=R[1]-R[0];
  for(j=1;j<=n-1;j++){
    if(maxv<R[j]-minv) maxv=R[j]-minv;
    if(minv>R[j]) minv=R[j];
  }
  printf("%d\n",maxv);
  return 0;
}
