#include<stdio.h>

int main(void)
{
  int k,s,x=0,y=0,z=0,counter=0;
  scanf("%d %d",&k,&s);
  for(x=0;x<=k;x++)
    {
      for(y=0;y<=k;y++)
	{
	  if(s-(x+y) <= k && s-(x+y) >=0)
	    {
	      counter++;
	    }
	}
    }
    
  printf("%d\n",counter);
  return 0;
}
