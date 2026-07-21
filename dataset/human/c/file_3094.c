#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long int k, n; 
	long long int i, x, y;
	y = 0;
	scanf("%lld %lld", &k, &n);
	long long int a[2000000] = {0};
	for(i = 0; i < n; i++)
	{
		scanf("%lld", a + i);
	}
	x = a[n - 1] - a[0];
	for(i = 1; i < n; i++)
	{
		if(y == 0 || y > k - a[i] + a[i - 1])
		{
			y = k - a[i] + a[i - 1];
		}
	}
	
	if(x < y)
	{
		printf("%lld", x);
	}
	else printf("%lld", y);
}
