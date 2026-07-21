#include<stdio.h>
int main()
{
	long long int n, k;
	scanf("%lld %lld", &n, &k);
	long long int i;
	int a[200005];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
	}
	int b[200005];
	long long int l;
	int v[200005];
	for (i = 0; i < n; i++)
		v[i] = 0;
	b[0] = 0;
	v[0] = 1;
	l = 1;
	int now = a[0];
	long long int c[200005];
	c[0] = 0;
	while (v[now] == 0)
	{
		b[l] = now;
		c[now] = l;
		l++;
		v[now] = 1;
		now = a[now];
	}
	if (l > k)
	{
		printf("%d\n", b[k] + 1);
		return 0;
	}
	k -= l;
	k %= l - c[now];
	printf("%d\n", b[c[now] + k] + 1);
	return 0;
}
