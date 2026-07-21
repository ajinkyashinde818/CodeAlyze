#include<stdio.h>

#define N 1000000000

int main(){
  int x,n,i,a=-N,m=N;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&x);
    if(i>0 && a<x-m) a=x-m;
    if(i!=0 && m>x) m=x;
    if(i==0 && m>x) m=x;
    
 
  }
  printf("%d\n",a);
  return 0;
}
