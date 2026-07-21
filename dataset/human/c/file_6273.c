#include<stdio.h>
int main(void)
{
	int i,N,a[200002],A,min;
	
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	
	min=a[0];
	A = a[1]-a[0];
	
	for(i=1;i<N;i++)
	{
		if(a[i]<min)
		{
			min =a[i];
		}
		else if(a[i]-min>A)
		{
			A = a[i]-min;
		}
	}
	
	printf("%d\n",A);

	return 0;
}
