/*
  AOJ 2656
  Title:Taps
  @kankichi573
*/
#include <stdio.h>
#include <math.h>
#include <float.h>
#define min(x,y) (((x)<(y))?(x):(y))

double T,D,ta,tb,da,db;
double temp;
double diff;

main()
{
  double w;
  int i,j;
  
  scanf("%lf %lf",&T,&D);
  scanf("%lf %lf",&ta,&tb);
  scanf("%lf %lf",&da,&db);

  if(ta>tb)
    w=ta,ta=tb,tb=w,w=da,da=db,db=w;

  if(T<=ta)
    diff=(double)ta-T;
  else if(T>=tb)
    diff=(double)T-tb;
  else
    {
      diff=100.0;
      for(i=0;i*da<=D;i++)
	for(j=0;i*da+j*db<=D;j++)
	  {
	    if(i==0 && j==0)
	      continue;
	    temp=(ta*i*da+tb*j*db)/(i*da+j*db);
	    //printf("%lf %lf %lf \n",i*da,j*db,temp);
	    diff=min(diff,fabs(T-temp));
	  }
    }
  printf("%lf\n",diff);
  return(0);
}
