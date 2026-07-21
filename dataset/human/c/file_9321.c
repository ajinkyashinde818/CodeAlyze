#include <stdio.h>

int main(){
  int n,k,ans=0;
  scanf("%d %d",&n,&k);
  
  int h[n+1];
  for(int i=1;i<=n;i++){
    scanf("%d",&h[i]);
  }
  
  for(int i=1;i<=n;i++){
    if(h[i]>=k){
      ans+=1;
    }
  }
  printf("%d",ans);
  return 0;
}
