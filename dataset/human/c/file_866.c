#include<stdio.h>
#include<stdlib.h>
typedef long long ll;
int main(void)
{
  ll n,cn,ans=0;
  scanf("%lld",&n);
  cn=n;
  if(n==1){
    printf("0");
    return 0;
  }
  for(ll i=2;i*i<=cn;i++){
    if(n%i==0){
      ll cnt=0;
      while(n%i==0){
        cnt++;
        n/=i;
      }
      ll k=1;
      while((cnt-k)>=0){
        ans++;
        cnt-=k;
        k++;
      }
    }
  }
  if(n>1) ans++;
 
  printf("%lld\n",ans);
  return 0;

}
