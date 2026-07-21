#include <stdio.h>
#include <limits.h>
int n;
long long mmin = LLONG_MAX;
long long su[220000], ar[220000];
long long abs(long long a)
{
	return a > 0 ? a : -a;
}
long long min(long long a, long long b)
{
	return a > b ? b : a;
}
int main()
{
	scanf("%d", &n);
	scanf("%lld", &ar[0]);
	su[0] = ar[0];
	for (int i = 1; i < n; i++)
	{
		scanf("%lld", &ar[i]);
		su[i] = ar[i] + su[i - 1];
	}
	for (int i = 0; i < n-1; i++)
	{
		//printf(">%d: %lld %lld\n", i, su[n - 1] - su[i], su[i]);
		mmin = min(abs(su[n - 1] - su[i]-su[i]), mmin);
	}
	printf("%lld\n", mmin);
}
