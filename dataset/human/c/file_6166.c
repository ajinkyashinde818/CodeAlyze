#include <stdio.h>
#include <limits.h>


int main(void)
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i , j;
	int max = INT_MIN;
	int min;
	for( i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	min = a[0];
	
	for( i = 1; i < n; i++)
	{
		if(max > (a[i]-min)){}
			else{
				max = a[i] - min;
			}
			if( min < a[i]){}
			else{
				min = a[i];
			}
	}
	
	printf("%d\n",max);
	
	return 0;
}
