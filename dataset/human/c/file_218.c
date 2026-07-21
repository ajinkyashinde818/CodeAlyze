#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	long long int a[100005];
	for (i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	int count = 0;
	long long int sum = 0;
	long long int min = 2000000009;
	for (i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			count++;
			a[i] *= -1;
		}
		sum += a[i];
		if (min > a[i])
			min = a[i];
	}
	if (count % 2 == 0)
		printf("%lld\n", sum);
	else
		printf("%lld\n", sum - 2 * min);
	return 0;
}
