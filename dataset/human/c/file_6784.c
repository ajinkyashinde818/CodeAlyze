#include<stdio.h>
#define ll long long
#define MAX 1000000000

ll n,k;
ll a[212345];

int main(){
  scanf("%lld%lld",&n,&k);
  for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);}

  ll l=0,r=MAX+1;
  while(l<r){
    if(l+1==r) break;
    ll mid=(l+r)/2;
    ll count=0;
    for(int i=0;i<n;i++){
      count+=(a[i]-1)/mid;}
    if(count<=k) r=mid;
    else l=mid;}

  printf("%lld\n",r);
  return 0;
}
