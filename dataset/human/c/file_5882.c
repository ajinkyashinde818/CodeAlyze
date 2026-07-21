#include<stdio.h>

#define MAX 1000000000
#define MIN -1000000000

int main()
{
  int n,x,y=0,min=MAX,max=MIN,i;

  scanf("%d",&n);
  
  scanf("%d",&x);
  if(min>x)min=x;
  
  for(i=1;i<n;i++)
    {
      scanf("%d",&x);

      if(max<(x-min))max=x-min;
      if(min>x)min=x;

    }

  printf("%d\n",max);

  return 0;
}
