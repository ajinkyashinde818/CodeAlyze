#include <stdio.h>

int main() {
	int n, i, x;
	long long int m, y, a;
	scanf("%d", &n);
	m = 0;
	x = 0;
	y = 0;
	for (i = 0; i < n; i++) {
		scanf("%lld", &a);
		if (a < 0) {
			x++;
			a = -a;
		}
		if (i == 0 || y > a) y = a;
		m += a;
	}
	if (x % 2 == 1) m -= y * 2;
	printf("%lld", m);
}
