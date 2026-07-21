#include <stdio.h>
int a,b,k,cnt;
int min(int x,int y){
  return x<y?x:y;
}
int main(void){
  scanf("%d%d%d",&a,&b,&k);
  int ans;
  for(ans=min(a,b);ans>=1;--ans)
    if(a%ans==0&&b%ans==0){
      ++cnt;
      if(cnt==k) break;
    }
  printf("%d\n",ans);
  return 0;
}
