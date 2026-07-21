#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,i;
  scanf("%d",&n);
  long long a[n+1],total=0;
  for(i=0;i<n;i++){
    scanf("%lld",&a[i]);
    total+=a[i];
  }
  i=1;
  long long sa=total-2*a[0];
  long long min=llabs(sa);
  for(i=1;i<n-1;i++){
    sa-=2*a[i];
    if(llabs(sa)<min)
      min=llabs(sa);
  }
  printf("%lld\n",min);
  return 0;
}
