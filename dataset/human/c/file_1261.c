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
		a = a * a % p;
		n /= 2;
	}
	return res;
}
int main()
{
	long long int n;
	scanf("%lld", &n);
	long long int i, j;
	long long int x[100005];
	for (i = 0; i < n; i++)
		scanf("%lld", &x[i]);
	long long int p = 1000000007;
	long long int ans = 0;
	long long int f = 1;
	for (i = 1; i < n; i++)
		f = f * i % p;
	long long int sum[100005];
	sum[0] = 0;
	for (i = 0; i < n; i++)
		sum[i + 1] = (sum[i] + modpow(i + 1, p - 2, p)) % p;
	for (i = 1; i < n; i++)
		ans = (ans + (x[i] - x[i - 1]) * f % p * sum[i] % p) % p;
	printf("%lld\n", ans);
	return 0;
}
