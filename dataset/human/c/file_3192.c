#include <stdio.h>

int main(void)
{
	int k,n;
	scanf("%d%d", &k, &n);
	int a[n];
	int i = 0;
	while (i < n)
		scanf("%d", &a[i++]);
	int max = 0;
	i = 1;
	while (i < n)
	{
		if (a[i] - a[i - 1] > max)
			max = a[i] - a[i - 1];
		i++;
	}
	if (max < k - a[n - 1] + a[0])
		max = k - a[n - 1] + a[0];
	printf("%d", k - max);
	return (0);
}
