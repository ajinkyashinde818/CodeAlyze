#include <stdio.h>

int main() {
	int i, n, a[50], b[60], c[60], ans = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);

	for (i = 0; i < n -1; i++)
		scanf("%d", &c[i]);

	for (i = 0; i < n - 1; i++) {
		ans += b[a[i] -1];
		if (a[i] == (a[i + 1] - 1)) {
			ans += c[a[i] - 1];
		}
	}

	ans += b[a[n - 1] - 1];

	printf("%d\n", ans);
	
	return 0;
}
