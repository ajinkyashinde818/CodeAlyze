#include <stdio.h>
#define MAX 200000
#define MIN -2000000000
int main(){

  int i,x,n,R[MAX],minv=0,maxv=MIN;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
}
  minv=R[0];
  for(i=1;i<n;i++){
    x=R[i]-minv;
    if(maxv<x)maxv=x;
    if(minv>R[i])minv=R[i];
  }
  printf("%d\n",maxv);

  return 0;
}
