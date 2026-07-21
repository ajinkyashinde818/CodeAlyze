#include <stdio.h>

int main(void) {
	int n, ans = 0;
	int a[20], b[20], c[19];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d", &c[i]);
	}

	int old = a[0];
	for (int i = 0; i < n; ++i) {
		ans += b[a[i]-1];
		if (a[i] - old == 1) {
			ans += c[old - 1];
		}
		old = a[i];

	}
	printf("%d", ans);

	return 0;
}
