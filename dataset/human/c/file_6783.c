#include<stdio.h>
#include<stdlib.h>
int main(){
  long long ng=0,ok=1e18,n,m,k,s,a[200010],i;
  scanf("%lld %lld",&n,&k);
  for(i=0;i<n;i++)scanf("%lld",&a[i]);
  while(labs(ng-ok)>1){
    m=(ok+ng)/2;
    for(i=s=0;i<n;i++){
      s+=(a[i]-1)/m;//printf("%d\n",s);
    }//printf("%lld %lld\n",m,s);
    if(s>k)ng=m;
    else   ok=m;
  }
  printf("%lld\n",ok);
  return 0;
}
