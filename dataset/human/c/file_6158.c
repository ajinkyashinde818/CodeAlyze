#include<stdio.h>

int main(void)
{
	int n;
	
	scanf("%d", &n);
	
	int i, j, R[n];

	for(i=0; i<n; i++)
	{
		scanf("%d", &R[i]);
	}
	
	int min=R[0], max=R[1]-R[0];
	
	for(i=1; i<n; i++)
	{
		if(R[i]-min>max)
		{
			max = R[i]-min;
		}
		
		if(R[i]<min)
		{
			min = R[i];
		}
	}
	
	printf("%d\n", max);
	
//	printf("max = %d, min = %d", max, min);
	
	return 0;
}
