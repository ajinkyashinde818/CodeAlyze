#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int n;
  int loop,path,tmp;
  long long int k;
  int a[200001]={0};
  int town[200001]={0,1};
  int i;

  scanf("%d %lld",&n,&k);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i+1]);
  }

  i=1;
  tmp=1;
  while(1)
  {
    if(i==k)
    {
      printf("%d\n",a[tmp]);
      return 0;
    }
    if(town[a[tmp]]>0)
    {
      loop=i+1-town[a[tmp]];
      path=town[a[tmp]];
      break;
    }
    else town[a[tmp]]=i+1;
    i++;
    tmp=a[tmp];
  }

  k=(k-path+1)%loop+path;

  for(i=1;i<=200000;i++)
  {
    if(town[i]==k)
    {
      printf("%d\n",i);
      break;
    }
  }

  return 0;
}
