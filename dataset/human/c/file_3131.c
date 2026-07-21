#include <stdio.h>
#include<string.h>

int main()
{
  int k,n;

  scanf("%d %d",&k,&n);
 
  int a[n+2];
  int i;
  int l[n+2];
  int max_l=0;
  int num=1;
  long long sum=0;
  
  for(i=0;i<=n+1;i++)
  {
    a[i]=0;
    l[i]=0;
  }
  
  for(i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
  }
  
  for(i=1;i<n;i++)
  {
   l[i]=a[i+1]-a[i];
  }
  l[n]=k-a[n]+a[1];
  
  max_l=l[1];
  for(i=2;i<=n;i++)
  {
    if(max_l<l[i])
    {
      max_l=l[i];
      num=i;
    }
  }
  
  sum=k-l[num];
/*  for(i=1;i<=n;i++)
  {
    if(i!=num)
    {
    sum+=l[i];
    }
    
  }*/
  
  printf("%lld\n",sum);
  return 0;
}
