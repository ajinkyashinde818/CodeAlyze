#include <stdio.h>

int main() {
	int n, d, x, a[100], i, j, cnt = 0;

	scanf("%d %d %d", &n, &d, &x);
	for (i = 0; i<n; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i<n; i++) {
		for (j = 1; j <= d; j += a[i]) {
			cnt++;
		}
	}

	printf("%d\n", cnt + x);

	return 0;
}
