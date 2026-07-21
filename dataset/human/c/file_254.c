#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  long long a[100000];
  long long sum;
  long long tmp;
  int flag=0;
  int zflag=0;
  scanf("%d\n",&n);
  for(int i=0;i<n;i++) scanf("%lld",&a[i]);
  sum=llabs(a[0]);
  tmp=llabs(a[0]);
  if(a[0]<0) flag=1;
  if(a[0]==0) zflag=1;
  for(int i=1;i<n;i++) {
    sum+=llabs(a[i]);
    if(llabs(a[i])<tmp) tmp=llabs(a[i]);
    if(a[i]<0) flag=(flag+1)%2;
    if(a[i]==0) zflag=1;
  }
  if(zflag||flag) sum-=tmp*2;
  printf("%lld",sum);
  return 0;
}
