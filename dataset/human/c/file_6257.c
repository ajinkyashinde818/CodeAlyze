#include <stdio.h>
#define MAX 200000
int main()
{
  int i,j,maxv,minv,R[MAX],n;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }

for(j=1;j<=n-1;j++){
  for(i=0;i<=j-1;i++){
    if(maxv>R[j]-R[i]){
      maxv=maxv;
    }
    if(maxv<R[j]-R[i]){
      maxv=R[j]-R[i];
    }
  }
 }

  minv=R[0];
  maxv=R[1]-R[0];
  for(j=1;j<=n-1;j++){
    if(maxv>R[j]-minv){
      maxv=maxv;
    }
    if(maxv<R[j]-minv){
      maxv=R[j]-minv;
    }
    if(minv>R[j]){
      minv=R[j];
    }
    if(minv<R[j]){
      minv=minv;
    }
  }
  printf("%d\n",maxv);

  return 0;
}
