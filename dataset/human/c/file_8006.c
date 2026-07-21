#include<stdio.h>
long long int modpow(long long int a, long long int n, long long int p)
{
	if (n < 0)
		return 0;
	long long int res = 1;
	while (n > 0)
	{
		if (n % 2 > 0)
			res = res * a % p;
		n /= 2;
		a = a * a % p;
	}
	return res;
}
int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	long long int p = 1000000007;
	int a, b;
	if (2 * y - x < 0)
	{
		printf("0\n");
		return 0;
	}
	if ((2 * y - x) % 3 > 0)
	{
		printf("0\n");
		return 0;
	}
	a = (2 * y - x) / 3;
	if (2 * x - y < 0)
	{
		printf("0\n");
		return 0;
	}
	if ((2 * x - y) % 3 > 0)
	{
		printf("0\n");
		return 0;
	}
	b = (2 * x - y) / 3;
	long long int i;
	long long int k[2000006];
	k[0] = 1;
	for (i = 1; i < 2000006; i++)
		k[i] = k[i - 1] * i % p;
	long long int ans = k[a + b];
	ans = ans * modpow(k[a], p - 2, p) % p;
	ans = ans * modpow(k[b], p - 2, p) % p;
	printf("%lld\n", ans);
	return 0;
}
