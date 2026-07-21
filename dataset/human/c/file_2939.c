#include<stdio.h>

int main(){
  int k = 0;
  int s = 0;
  int i = 0;
  int j = 0;
  long long cnt = 0;
  scanf("%d %d",&k,&s);
  for(i=0;i<=k;i++){
    for(j=0;j<=k;j++){
      if(0 <= s-j-i && s-j-i <= k){
        cnt++;
      }
    }
  }
  
  printf("%lld",cnt);
  return 0;
}
