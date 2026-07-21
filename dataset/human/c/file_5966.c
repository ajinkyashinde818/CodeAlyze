#include<stdio.h>
int main(void)
{
	
	int n,i,j;
	
	scanf("%d",&n);
	int R[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&R[i]);
	}
	int maxv=R[1]-R[0];
	int minv=R[0];
	for(j=1;j<n;j++)
	{
		
		if(maxv<R[j]-minv)
		{
			maxv=R[j]-minv;
		}
		if(minv>R[j])
		{
			minv=R[j];
		}
	}
	printf("%d\n",maxv);
	return 0;
}
