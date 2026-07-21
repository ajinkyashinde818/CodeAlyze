#include<stdio.h>

int main(){
  int n,k; scanf("%d%d",&n,&k);
  int sum=0,y0,y,max=0; scanf("%d",&y); y0=y;
  for(int i=0; i<k; i++){
    int x; scanf("%d",&x);
    sum+=(x-y);
    if(x-y>max) max=x-y;
    y=x;
   //printf("%d %d\n",sum,max);
  } 
  sum+=(y0+n-y);
  if(y0-y+n>max) max=y0-y+n;
  printf("%d\n",sum-max);
  return 0;
}
