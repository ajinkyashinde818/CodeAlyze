#include<stdio.h>

int main(){
  int i,j,k;
  long long int x,ans=0;
  scanf("%lld",&x);
  
  ans += (x/11)*2;
  x %= 11;
  if(x!=0){
  if(x >6)
    ans+=2;
  else
    ans++;
  }
  printf("%lld\n",ans);
  return 0;
}
