/*
  AOJ #3129
  title:Contest T-shirts
  @kankichi57301
  2020/02/28 
 */
#include <stdio.h>
#define min(x,y) (((x)<(y))?(x):(y))

int n,m;
int main()
{
  int i,c,c0,r,ret;
  scanf("%d %d",&m,&n);
  ret=r=0;

  if(m==2)
  {
      for(i=0;i<n;i++)
      {
	scanf("%d",&c);
	if((c-1)== (i & 1))
	   r++;
      }
      //printf("n=%d:r=%d\n",n,r);
      ret = min(r,n-r);
  }
  else
  {
    scanf("%d ",&c0);
    for(i=1;i<n;i++)
    {
      scanf("%d",&c);
      if(c == c0)
	ret++,c0=0;
      else
	c0=c;
    }
  }
  printf("%d\n",ret);
 
  return(0);
}
