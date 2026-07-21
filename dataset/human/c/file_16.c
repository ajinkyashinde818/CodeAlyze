#include <stdio.h>
int main() {
	int n, r, g, b;
	scanf("%d%d%d%d", &r, &g, &b, &n);
	long long ans = 0;
	for (int i = 0; i <= n/r; i++) {
		for (int j = 0; j <= n/g; j++) {
			if (i * r + j * g <= n && (n - i * r - j * g) % b == 0)ans++;
		}
	}
	printf("%lld\n", ans);
}
