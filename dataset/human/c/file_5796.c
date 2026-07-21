#include<stdio.h>
#define N 200000
int main(){
 
  int i,j,R[N],n,maxv=0,minv;
 
  scanf("%d",&n);
 
  for(j=0;j<n;j++) scanf("%d",&R[j]);
 
  minv = R[0];
  maxv = R[1] - R[0];
  for(j=1;j<n;j++){
    if( maxv < R[j]-minv ) maxv = R[j] - minv;
    else maxv = maxv;
    if( minv < R[j] ) minv = minv;
    else minv = R[j];
  }
 
  printf("%d\n",maxv);
  return 0;
}
