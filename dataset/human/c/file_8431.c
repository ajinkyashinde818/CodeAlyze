#include<stdio.h>
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int i, j;
	long long int a[1003];
	for (i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	long long int sum[1003];
	sum[0] = 0;
	for (i = 0; i < n; i++)
		sum[i + 1] = sum[i] + a[i];
	int m = 0;
	long long int b[1000006];
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			b[m] = sum[j + 1] - sum[i];
			m++;
		}
	}
	long long int ans = 0;
	long long int v;
	v = 1;
	while (v <= sum[n])
		v *= 2;
	int count;
	while (v > 0)
	{
		count = 0;
		for (i = 0; i < m; i++)
			if ((b[i] & (ans + v)) == (ans + v))
				count++;
		if (count >= k)
			ans += v;
		v /= 2;
	}
	printf("%lld\n", ans);
	return 0;
}
