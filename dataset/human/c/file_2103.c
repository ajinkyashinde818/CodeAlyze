#include<stdio.h>
int main(void){
  long long n,ans;
  scanf("%lld",&n);
  for(long long i=10;i<=n;i*=5){
    ans+=(n/i);
  }
  if(n%2){
    printf("0\n");
  }else{
    printf("%lld\n",ans);
  }
  return 0;
}
