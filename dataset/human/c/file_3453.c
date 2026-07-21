#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long ll;
int main(void)
{
  ll n,k;
  scanf("%lld%lld",&n,&k);
  ll a[n+1],b[n+1],ans=1;
  for(ll i=1;i<=n;i++){
    scanf("%lld",&a[i]);
    b[i]=0;
  }
  ll tmp1=0,tmp2=0;
  for(ll i=1;i<=k;i++){
    b[ans]++;
    if(b[ans]==2){
      tmp1++;
    }
    if(b[ans]==3){
      tmp2=i;
      break;
    }
    ans=a[ans];
    if(i==k){
      printf("%lld",ans);
      return 0;
    }
  }
  //printf("%lld",tmp1);
  ll c[tmp2],tmp3=1;
  for(ll i=0;i<=(tmp2-1);i++){
    c[i]=tmp3;
    tmp3=a[tmp3];
  }
  printf("%lld",c[tmp2-tmp1+(k-tmp2)%tmp1]);

  return 0;
}
