#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,i,sw;
  sw=0;
  scanf("%d",&n);
long long int a[n],sum[n],ans,temp;
  scanf("%lld",&a[0]);
  sum[0]=a[0];
  for(i=1;i<n;++i)
  {
  scanf("%lld",&a[i]);
  sum[i]=sum[i-1]+a[i];
  }
  int cc=0;
  
  ans=llabs(sum[n-1]-sum[0]*2);
    for(i=1;i<n-1;++i)
    {
    temp=llabs(sum[n-1]-sum[i]*2);
    if(temp<ans) ans=temp;
    }
  printf("%lld",ans);
return 0;}
