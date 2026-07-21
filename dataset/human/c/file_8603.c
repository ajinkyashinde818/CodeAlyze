#include<stdio.h>

int main(void)
{
  int n,buf[100001],i,j,frag=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&buf[i]);
      if(buf[i] == 2)
	{
	  frag = 1;
	}
    }
  if(frag == 0) //不可能な場合
    {
      printf("-1\n");
      return 0;
    }
  i=0;
  for(j=0;j<n;j++)
    {
      if(buf[i] != 2)
	{
	  i = buf[i] - 1;
	}
      else
	{
	  j++;
	  frag = 0;
	  break;
	}
    }
  if(frag == 0)
    {
      printf("%d\n",j);
    }
  else
    {
      printf("-1\n");
    }
  return 0;
}
