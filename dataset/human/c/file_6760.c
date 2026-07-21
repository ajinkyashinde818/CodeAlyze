#include <stdio.h>
int n, k, l, r, m, x;
int a[200000];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	r = 1000000000;
	while (l + 1 < r) {
		m = (l + r) / 2;
		x = 0;
		for (int i = 0; i < n; i++) {
			x += (a[i] - 1) / m;
		}
		if (x <= k)r = m;
		else l = m;
	}
	printf("%d\n", r);
}
