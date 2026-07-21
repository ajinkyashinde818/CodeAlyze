#include<stdio.h>

int main()
{
	int r[200000],n,i;
	int minv,maxv;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&r[i]);
	}
	minv=r[0];
	maxv=r[1]-r[0];
	for(i=1;i<n;i++)
	{
		maxv=maxv>r[i]-minv?maxv:r[i]-minv;
		minv=minv<r[i]?minv:r[i];
	}
	printf("%d\n",maxv);
	return 0;
}
