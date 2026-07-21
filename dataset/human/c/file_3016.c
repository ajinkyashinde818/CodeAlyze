#include <stdio.h>
int k, n, ans;
int a[200000];
int main() {
	scanf("%d%d", &k, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	ans = a[n - 1] - a[0];
	for (int i = 1; i < n; i++) {
		if (ans > k - (a[i] - a[i - 1]))ans = k - (a[i] - a[i - 1]);
	}
	printf("%d\n", ans);
}
