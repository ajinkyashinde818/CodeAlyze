#include <stdio.h>
#define N 200000
int main()
{
  int r[N],ri,rj[N],n,i,j,ie=0,je=0,imax,max;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&r[i]);
  for(i=0;i<n;i++)
    {
      if(i==0)
	{
	  ri=r[i];
	  ie++;
	  for(j=ie;j<n;j++)
	    {
	      imax=r[j]-ri;
	      if(j==ie)
		max=imax;
	      if(imax>max)
		max=imax;	     
	    }
	  continue;
	}
      if(i>0&&ri<=r[i])
	{
	  ie++;
	  continue;
	}
      if(i>0&&ri>r[i])
	{
	  ri=r[i];
	  ie++;
	  for(j=ie;j<n;j++)
	    {
	      imax=r[j]-ri;
	      if(imax>max)
		max=imax;	     
	    }
	  continue;
	}
    }
  printf("%d",max);
  printf("\n");
  return 0;
}
