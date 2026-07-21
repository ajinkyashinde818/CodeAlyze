#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int a[200005], b[200005];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (i = 0; i < n / 2; i++)
	{
		b[i] ^= b[n - i - 1];
		b[n - i - 1] ^= b[i];
		b[i] ^= b[n - i - 1];
	}
	int left = n;
	for (i = 0; i < n; i++)
	{
		if (a[i] == b[i])
		{
			left = i;
			break;
		}
	}
	a[n] = -1;
	i = 0;
	while (left < n)
	{
		if (a[left] != b[left])
			break;
		while ((a[i] == b[left] || b[i] == a[left]) && i < n)
			i++;
		if (i < n)
		{
			b[i] ^= b[left];
			b[left] ^= b[i];
			b[i] ^= b[left];
			left++;
		}
		else
			break;
	}
	left = 0;
	for (i = 0; i < n; i++)
		if (a[i] == b[i])
			left++;
	if (left > 0)
		printf("No\n");
	else
	{
		printf("Yes\n");
		for (i = 0; i < n - 1; i++)
			printf("%d ", b[i]);
		printf("%d\n", b[n - 1]);
	}
	return 0;
}
