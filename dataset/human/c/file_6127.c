#include<stdio.h>

int main(){
  int minv,maxv,n,x,i,j;

  scanf("%d",&n);
  scanf("%d",&minv);
  scanf("%d",&x);
  maxv=x-minv;
  if(x<minv)minv=x;
  
  for(j=1; j<n-1; j++){
    scanf("%d",&x);
    if(maxv<x-minv)maxv=x-minv;
    if(minv>x)minv=x;
  }

  printf("%d\n",maxv);

  return 0;
}
