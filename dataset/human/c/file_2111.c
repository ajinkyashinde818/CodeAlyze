#include<stdio.h>
#include<stdbool.h>
#define ll long long
ll cnt_2=0,cnt_5=0;
int main(){
  ll n,ans;
  scanf("%lld",&n);
  if(n%2!=0){
    printf("0");
    return 0;
  }
  ll a=n,b=n;
  while(a>0){
    a/=2;
    cnt_2+=a;
  }
  b/=10;
  cnt_5+=b;
  while(b>0){
    b/=5;
    cnt_5+=b;
  }
  ans=cnt_2<cnt_5?cnt_2:cnt_5;
  printf("%lld",ans);
  return 0;
}
