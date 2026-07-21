#include <stdio.h>

int main(void) {

	int k, n, tmp, max = 0, sum = 0, ans;
	int a[200001];

	scanf("%d %d", &k, &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= n-1; i++) {
		tmp = a[i + 1] - a[i];
		sum += tmp;
		if (tmp > max) max = tmp;
	}

	tmp = k + a[1] - a[n];
	sum += tmp;
	if (tmp > max) max = tmp;

	ans = sum - max;

	printf("%d",ans);

	return 0;
}
