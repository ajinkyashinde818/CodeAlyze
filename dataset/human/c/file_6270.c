#include<stdio.h>

int main()
{
  int n,x,i=0,min=2000000000,max=-2000000000;
  
  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&x);
      if(max <= x-min)max = x-min;
      if(min>=x)min=x;
      
    }
  printf("%d\n",max);

  return 0;
}
