#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define M 1000000007
#define ll long long

ll fact[2000003],ifact[2000003];

ll mpow(ll x,ll n){
  ll ans = 1;
  while(n!=0){
    if(n&1) ans=ans*x%M;
    x = x*x%M;
    n=n>>1;
  }
  return ans;
}

ll combi(ll n,ll r){
  if(n==0&&r==0)return 1;
  if(n<r||n<0)return 0;
  ll tmp = ifact[r]*ifact[n-r]%M;
  return fact[n]*tmp%M;
}

int main(){
  ll x,y,k,m,n;
  scanf("%lld %lld",&x,&y);
  if((2*x-y)%3!=0||(2*y-x)%3!=0||2*x<y||2*y<x){
  	printf("0");
    return 0;
  }
  n=(2*x-y)/3;
  m=(2*y-x)/3;
  fact[0]=1;
  ifact[0]=1;

  for(ll i=0;i<2000004;i++){
    fact[i+1]=fact[i]*(i+1)%M;
    ifact[i+1]=ifact[i]*mpow(i+1,M-2)%M;
  }

  printf("%lld\n",combi(n+m,m)%M);
  return 0;
}
