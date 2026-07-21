#include<stdio.h>
long long int prime(long long int n)
{
	if (n < 2)
		return 0;
	long long int i;
	for (i = 2; i * i <= n; i++)
		if (n % i == 0)
			return i;
	return n;
}
int main()
{
	long long int n;
	scanf("%lld", &n);
	long long int p;
	long long int cnt;
	long long int v;
	long long int ans = 0;
	while (n > 1)
	{
		p = prime(n);
		cnt = 0;
		while (n % p == 0)
		{
			cnt++;
			n /= p;
		}
		v = 1;
		while (v * (v + 1) / 2 <= cnt)
			v++;
		ans += v - 1;
	}
	printf("%lld\n", ans);
	return 0;
}
