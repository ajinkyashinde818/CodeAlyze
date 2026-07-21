#include<stdio.h>
int main(){
  int c,i,k,n;
  c = 0;
  int h[100001];
  scanf("%d%d",&n,&k);
  for(i=0;i<n;i++){scanf("%d",&h[i]);}
  for(i=0;i<n;i++){if(h[i]>=k)c++;}
  printf("%d",c);
}
