#include <stdio.h>
long long gcd(long long gcd_a, long long gcd_b) {
	if (gcd_a < gcd_b) {
		long long gcd_c;
		gcd_c = gcd_a;
		gcd_a = gcd_b;
		gcd_b = gcd_c;
	}
	if (!gcd_b)return gcd_a;
	return gcd(gcd_b, gcd_a % gcd_b);
}
long long n, m, l, x;
long long a[100000];
long long b[100000];
int main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", a + i);
		l = a[i];
		while (l % 2 == 0) {
			b[i]++;
			l /= 2;
		}
	}
	for (int i = 1; i < n; i++) {
		if (b[i] != b[i - 1]) {
			printf("0\n");
			return 0;
		}
	}
	l = b[0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++) {
			a[i] /= 2;
		}
	}
	x = a[0];
	for (int i = 1; i < n; i++) {
		x = x * a[i] / gcd(x, a[i]);
		if (x > m) {
			printf("0\n");
			return 0;
		}
	}
	for (int i = 1; i < l; i++) {
		x *= 2;
		if (x > m) {
			printf("0\n");
			return 0;
		}
	}
	printf("%lld\n", (m / x + 1) / 2);
}
