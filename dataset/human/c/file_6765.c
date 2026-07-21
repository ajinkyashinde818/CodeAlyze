#include <stdio.h>

int main(void){
  long long n,k,a[200005],x=1000000000,c=0,count=0,max=0;
  scanf("%lld %lld",&n,&k);
  for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);
    if(max<a[i]) max=a[i];
  }
  long long d=max+10;
  while(d-c>1){
    x=(d+c)/2;
    for(int i=0;i<n;i++){
      count+=(a[i]-0.001)/x;
        }
    if(count>k) c=x;
    else d=x;
    count=0;
  }
  printf("%lld",d);
  return 0;
}
