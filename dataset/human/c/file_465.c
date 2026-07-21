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
ll a[212345],b[212345];
ll c[212345];

int main(){
  scanf("%lld",&n);
  for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);}
  for(int i=0;i<n;i++){
    scanf("%lld",&b[i]);}

  int indb=0,maxc=0,maxd=0;
  for(int i=0;i<n;i++){
    while(indb<n && a[i]>=b[indb]) indb++;
    maxc=max(indb-i,maxc);}
  indb=n-1;
  for(int i=n-1;i>=0;i--){
    while(indb>=0 && a[i]<=b[indb]) indb--;
    maxd=max(maxd,i-indb);}
  if(maxc+maxd>n) puts("No");
  else{
    puts("Yes");
    for(int i=maxc;i<n;i++){
      printf("%lld ",b[i]);}
    for(int i=0;i<maxc;i++){
      printf("%lld ",b[i]);}
    puts("");
  }

  
  return 0;
}
