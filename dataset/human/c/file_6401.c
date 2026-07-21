#include <stdio.h>
int main (void)
{
	int n,i,j,maxv,minv;
	scanf("%d",&n);
	int x[n];
	
	for(i=0;i<n;i++)
	{
		scanf("%d", &x[i]);
	}
	
	minv=x[0];
	maxv=-x[0];
	for(j=1;j<=n-1;j++)
	{
		
		if(maxv<x[j]-minv)maxv=x[j]-minv;
		if(minv>x[j])minv=x[j];
	}
	printf("%d\n",maxv);
}
