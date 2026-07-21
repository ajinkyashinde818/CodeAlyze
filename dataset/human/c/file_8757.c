#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int a[100005];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int v[100005];
	for (i = 0; i <= n; i++)
		v[i] = 0;
	v[1] = 1;
	int now = 1;
	int ans = 0;
	while (now != 2)
	{
		now = a[now - 1];
		ans++;
		if (v[now] > 0)
		{
			printf("-1\n");
			return 0;
		}
		v[now]++;
	}
	printf("%d\n", ans);
	return 0;
}
