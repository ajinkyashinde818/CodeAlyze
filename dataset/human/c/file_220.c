#include<stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d", &n);
	long long int arr[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%lld", &arr[i]);
	}
	int count = 0;
	long long int min = 1000000000;
	for(i=0;i<n;i++)
	{
		if(arr[i]<0)
			count++;
		if(abs(arr[i])<min)
			min = abs(arr[i]);
	}
	long long int sum = 0;
	if(count%2==0)
	{
		for(i=0;i<n;i++)
		{
			sum = sum + abs(arr[i]);
		}
	printf("%lld", sum);
	}

	else 
	{
		for(i=0;i<n;i++)
		{
			sum = sum + abs(arr[i]);
		}
	printf("%lld", sum - min - min);
	}
}
