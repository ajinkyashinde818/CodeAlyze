#include <stdio.h>

int main(void)
{
	long i, k, n, max;
	scanf("%ld", &k);
	scanf("%ld", &n);
	long a[n];
	for (i = 0; i < n; i++)
		scanf("%ld", &a[i]);
	max = a[0];
	for (i = 0; i < (n-1); i++)
	{
		if (max < (a[i + 1] - a[i]))
			max = a[i + 1] - a[i];
	}

	if(max < (k-a[n-1]+a[0])) {
		max = k - a[n-1] + a[0];
	}
	printf("%ld\n", k - max);
	return 0;
}
