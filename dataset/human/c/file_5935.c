#include<stdio.h>
int main()
{
  int i,n,x,before,after,min;
  scanf("%d",&n);
  scanf("%d%d",&before,&after);
  if(before<after) min=before;
  else min=after;
  for(i=2;i<n;i++)
    {
      scanf("%d",&x);
      if(x>after) after=x;
      if(x-min>after-before)
	{
	  after=x;
	  before=min;
	}
      if(x<min) min=x;
    }
  printf("%d\n",after-before);
  return 0;
}
