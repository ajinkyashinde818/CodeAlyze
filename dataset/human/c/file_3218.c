#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
 long long int k,n,a[200001],i,d;
  
  scanf("%lld %lld",&k,&n);
  
  for(i=1;i<=n;i++)
  {
    scanf("%lld",&a[i]);
  }
  d=a[2]-a[1];
  for(i=2;i<n;i++)
  {
    if(d<(a[i+1]-a[i]))
    {
      d=a[i+1]-a[i];
    }
  }
  if(d<(a[1]+k-a[n]))
  {
    d=a[1]+k-a[n];
  }
  d=k-d;
  printf("%lld",d);
     
  
  return 0;
  
}
