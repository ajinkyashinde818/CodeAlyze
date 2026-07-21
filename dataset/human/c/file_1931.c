#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int a[22], b[22], c[22];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (i = 0; i < n - 1; i++)
		scanf("%d", &c[i]);
	int ans = b[a[0] - 1];
	for (i = 1; i < n; i++)
	{
		ans += b[a[i] - 1];
		if (a[i] == a[i - 1] + 1)
			ans += c[a[i - 1] - 1];
	}
	printf("%d\n", ans);
	return 0;
}
