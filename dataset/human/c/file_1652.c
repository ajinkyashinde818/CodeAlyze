#include <stdio.h>
int n;
int a[20], b[20], c[20];
int ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", b + i);
		ans += b[i];
	}
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", c + i);
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] + 1 == a[i + 1])ans += c[a[i] - 1];
	}
	printf("%d\n", ans);
}
