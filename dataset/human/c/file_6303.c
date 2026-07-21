#include<stdio.h>
int main(void)
{
  int ans=0;//output
  int num;//the number of input
  int i;//counter
  int x;//input
  int min;//the "current" minimum value
  scanf("%d",&num);
  for(i=0;i<num;i++)
    {
      scanf("%d",&x);
      if(i==0) min=x;
      else
	{
	  if(i==1) ans=x-min;
	  if(x-min>ans) ans=x-min;//update answer
	  if(min>x) min=x;//update minimum value
	}
    }
  printf("%d\n",ans);
  return 0;
}
