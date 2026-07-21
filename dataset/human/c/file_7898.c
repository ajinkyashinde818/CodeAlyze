#include<stdio.h>
long long int gcd(long long int a, long long int b)
{
	long long int r = a % b;
	while (r > 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
int main()
{
	long long int n, m;
	scanf("%lld %lld", &n, &m);
	long long int i;
	long long int a[100005];
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		a[i] /= 2;
	}
	long long int l = a[0];
	for (i = 0; i < n; i++)
		l = l / gcd(l, a[i]) * a[i];
	for (i = 0; i < n; i++)
	{
		if (l / a[i] % 2 == 0)
		{
			printf("0\n");
			return 0;
		}
	}
	printf("%lld\n", (m / l + 1) / 2);
	return 0;
}
