#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	long long int n, k, a[200020], i, j = 0, star, b[200020] = { 0 }, h=0, c = 0;
	scanf("%lld%lld", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	star = 1;
	while (1)
	{
		b[star]++;
		if (b[star] == 3)
		{
			break;
		}
		star = a[star];
	}
	for (i = 0; i <= n; i++)
	{
		if (b[i] == 1)
		{
			h++;
		}
		if (b[i] == 2 || b[i] == 3)
		{
			c++;
		}
	}
	if (k > h)
	{
		k = (k - h) % c;
	}
	else
	{
		star = 1;
	}
	for (i = 0; i < k; i++)
	{
		star = a[star];
	}
	printf("%lld", star);
	return 0;
}
