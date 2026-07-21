/*
  AOJ 0594
  Title:Super Metropolis
  @kankichi573
*/

#include <stdio.h>
#define Max(x,y) (((x)>(y))?(x):(y))
#define Min(x,y) (((x)<(y))?(x):(y))


int W,H,N;
int Sign(int x)
{
  if(x>0)
    return(1);
  if(x==0)
    return(0);
  if(x<0)
    return(-1);
}
int Abs(int x)
{
  return((x>0)?x:(-x));
}
int solve(int x1,int y1,int x2,int y2)
{
  if(Sign(x1-x2)!=Sign(y1-y2))
    return(Abs(x1-x2)+Abs(y1-y2));
  else
    return(Max(Abs(x1-x2),Abs(y1-y2)));
}
main()
{
  int x,y,xold,yold,res,i,ret;

  scanf("%d %d %d",&W,&H,&N);
  scanf("%d %d",&xold,&yold);
  {
    for(i=0,res=0;i<N-1;i++)
      {
	scanf("%d %d",&x,&y);
	ret = solve(xold,yold,x,y);
	//printf("%d %d %d %d =%d\n",xold,yold,x,y,ret);
	res += ret;
	xold=x;
	yold=y;
      }
    printf("%d\n",res);
  }
  return(0);
}
