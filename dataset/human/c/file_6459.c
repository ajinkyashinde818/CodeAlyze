#include<stdio.h>

int main(void)
{
	int i,j,n;
	long A[200000],Max,min;
	
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		scanf("%ld",&A[i]);
	}
	Max=-2000000000;
	min=A[0];
	for(i=1;i<=n-1;i++)
	{
		if(Max<A[i]-min)
		{
			Max=A[i]-min;
		}
		if(min>A[i])
		{
			min=A[i];
		}
	}
	printf("%ld\n",Max);
	return 0;
}
