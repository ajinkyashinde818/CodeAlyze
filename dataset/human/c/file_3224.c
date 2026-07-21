#include <stdio.h>

int main(void)
{
	long long k, n, t, max = 0;
	scanf("%lld%lld", &k, &n);
	long long a[n];
	for(t = 0; t < n; t++)
		scanf("%lld", &a[t]);

	max = a[1] - a[0];

	for(t = 0; t < n - 1; t++)
		if(max <= a[t + 1] - a[t])
			max = a[t + 1] - a[t];

	if(max <= k + a[0] - a[n - 1])
		max = k + a[0] - a[n - 1];

	printf("%lld", k - max);

	return 0;
}
