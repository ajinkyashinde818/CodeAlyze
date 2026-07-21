#include<stdio.h>

int main(){
  int n,k,i,h[100001],cnt=0;
  scanf("%d%d",&n,&k);
  for(i=1;i<=n;i++){
    scanf("%d",&h[i]);
    if(h[i]>=k)cnt++;
  }
  printf("%d",cnt);
  return 0;
}
