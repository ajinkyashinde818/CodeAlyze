#include "bits/stdc++.h"
using namespace std;
long long max(long long x, long long y)
{
	return x > y ? x : y;
}
long long a[100001], b[100001], c[2][100001], d[2][100001], e[2][100001];
int main()
{	
	int n;
	long long m, mx = 0, inf = 1ll << 60;
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld%lld", &a[i], &b[i]);
		b[i] += b[i - 1];
	}
	for(int i = 0; i < 2; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			d[i][j] = -inf;
			e[i][j] = -inf;
		}
		d[i][0] = 0;
		d[i][0] = 0;
	}
	for(int i = 1; i <= n; ++i)
	{
		c[0][i] = b[i] - a[i];
		d[0][i] = max(d[0][i - 1], c[0][i]);
	}
	for(int i = n; i; --i)
	{
		c[1][i] = b[n] - b[i - 1] - (m - a[i]);
		d[1][i] = max(d[1][(i + 1) % (n + 1)], c[1][i]);
	}
	for(int i = 1; i < n; ++i)
	{
		e[0][i] = c[0][i] + max(0, d[1][i + 1] - a[i]);
	}
	e[0][n] = c[0][n];
	for(int i = n; i > 1; --i)
	{
		e[1][i] = c[1][i] + max(0, d[0][i - 1] - (m - a[i]));
	}
	e[1][1] = c[1][1];
	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j <= n; ++j)
		{
			mx = max(mx, e[i][j]);
		}
	}
	printf("%lld\n", mx);
}
