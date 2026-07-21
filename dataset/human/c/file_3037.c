#include <stdio.h>

int a[222222];

int main(void)
{
	int k, n, i, max = 0;
	
	scanf("%d %d", &k, &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (i = 1; i < n; i++)
		if (max < a[i + 1] - a[i])
			max = a[i + 1] - a[i];
	if (max < k - a[n] + a[1])
		max = k - a[n] + a[1];

	printf("%d", k - max);
	return 0;
}
