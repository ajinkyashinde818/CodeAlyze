#include<stdio.h>

int main(void){
  long long n,k,a[524288],p,c,i;
  long long f[524288];
  scanf("%lld%lld",&n,&k);
  for(i=1;i<=n;i++){
    f[i]=-1;
    scanf("%lld",&a[i]);
  }
  f[1]=0;p=a[1];c=1;k--;
  while(k>0){
    if(f[p]!=-1){k%=(c-f[p]);}
    if(k==0){break;}
    f[p]=c;
    p=a[p];
    c++;k--;
  }
  printf("%lld\n",p);
  return 0;
}
