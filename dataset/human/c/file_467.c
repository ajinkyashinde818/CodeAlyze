#include <stdio.h>
int n;
long long s, x, y;
long long a[200000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", a + i);
		s += a[i];
	}
	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];
	}
	x = s - 2 * a[0];
	if (x < 0)x = -x;
	for (int i = 1; i < n - 1; i++) {
		y = s - 2 * a[i];
		if (y < 0)y = -y;
		if (y < x)x = y;
	}
	printf("%lld\n", x);
}
