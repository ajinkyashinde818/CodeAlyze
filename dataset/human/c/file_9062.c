#include "stdio.h"

int main(){
  int n,lim,h[100001],ans=0;
  scanf("%d %d",&n,&lim);
  for(int i=0;i<n;i++){
     scanf("%d",&h[i]);
    if(h[i]>=lim)ans++;
  }
 
  printf("%d",ans);
  return 0;
}
