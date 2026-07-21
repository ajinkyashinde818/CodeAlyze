#include<stdio.h>
#include<stdlib.h>
int asc(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int abs(int n)
{
	if (n < 0)
		n *= -1;
	return n;
}
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int a[100005];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), asc);
	int ans = a[n - 1] - a[0];
	for (i = 1; i < n - 1; i++)
		ans += abs(a[i]);
	printf("%d\n", ans);
	int x = a[0];
	for (i = n - 2; i > 0; i--)
	{
		if (a[i] < 0)
			break;
		printf("%d %d\n", x, a[i]);
		x -= a[i];
	}
	int y = a[n - 1];
	for (i = 1; i < n - 1; i++)
	{
		if (a[i] >= 0)
			break;
		printf("%d %d\n", y, a[i]);
		y -= a[i];
	}
	printf("%d %d\n", y, x);
	return 0;
}
