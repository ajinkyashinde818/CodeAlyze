#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int
main(void)
{
	int i, j, n;
	int *a;
	int max = INT_MIN;
	int ans = INT_MIN;

	scanf("%d", &n);
	if (n < 2)
		return 1;

	a = (int *)malloc(sizeof(int) * n);
	if (a == NULL)
		return 1;

	for (i = 0;i < n; i++) {
		scanf("%d", a + i);
	}

	for (i = n - 2; i >= 0 ; i--) {
		if (a[i + 1] > max)
			max = a[i + 1];
		if (ans < max - a[i])
			ans = max - a[i];
	}

	printf("%d\n", ans);

	return 0;
}
