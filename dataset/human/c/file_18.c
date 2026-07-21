#include "stdio.h"
int main ()
{
	int r,g,b,n;
	scanf ("%d %d %d %d",&r,&g,&b,&n);
	int i=0;
	for (int j=0;j<=n/r;j++)
	  for (int x=0;x<=n/g;x++)
	    { 
	      if (n-j*r-x*g>=0&&(n-j*r-x*g)%b==0)
	        i++;
		}
		
	printf ("%d",i);
	
	return 0;
}
