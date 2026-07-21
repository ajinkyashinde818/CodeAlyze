#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ll long long
#define mod 1000000007
#define max(p,q)((p)>(q)?(p):(q))
ll powe(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
ll n;
ll d1[212345],d2[212345];
ll c[212345];
char s[1010];

int main(){
  scanf("%lld",&n);
  int maxi=0,count=0;
  for(int i=0;i<n;i++){
    scanf("%lld%lld",&d1[i],&d2[i]);
    if(d1[i]==d2[i]) count++;
    else count=0;
    maxi=max(maxi,count);
  }

  if(maxi>=3) puts("Yes");
  else puts("No");

  
  return 0;
}
