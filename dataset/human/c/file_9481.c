#include<stdio.h>

int main(void)
{
  int n,day,r,eat[100],i,counter=0,t,ans=0;
  scanf("%d %d %d",&n,&day,&r);
  for(i=0;i<n;i++)
    {
      scanf("%d",&eat[i]);
      t=1;
      while(day >= t)
	{
	  counter++;
	  t = t + eat[i];
	}
    }
  ans = r + counter;
  printf("%d\n",ans);
  return 0;
}
