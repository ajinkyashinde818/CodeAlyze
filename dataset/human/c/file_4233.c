#include<stdio.h>
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int i;
	int a[100005], b;
	for (i = 0; i < 100005; i++)
		a[i] = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d", &b);
		a[b] = 2000;
	}
	int ans[100005];
	ans[0] = 1;
	if (a[1] > 0)
		ans[1] = 0;
	else
		ans[1] = 1;
	for (i = 2; i <= n; i++)
	{
		if (a[i] > 0)
			ans[i] = 0;
		else
			ans[i] = ans[i - 1] + ans[i - 2];
		ans[i] %= 1000000007;
	}
	printf("%d\n", ans[n]);
	return 0;
}
