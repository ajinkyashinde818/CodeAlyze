#include<stdio.h>
#include<limits.h>

int main(void)
{
	int i, n;
	scanf("%d", &n);
	
	int r[n];
	
	for(i = 0; i <= n - 1; i++)
	{
		scanf("%d", &r[i]);
	}
	
	int max = INT_MIN;
	int min = r[0];
	
	for(i = 1; i <= n - 1; i++)
	{
		if(max < r[i] - min) 
		{
		    max = r[i] - min;
		}
		
		if(min > r[i])
		{
		    min = r[i];
		}
	}
	
	printf("%d\n", max);
	
	return 0;
}
