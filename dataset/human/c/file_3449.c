#include <stdio.h>
long long n, k, s, x, y, z;
long long a[200000];
long long c[200000];
int main() {
	scanf("%lld%lld", &n, &k);
	for (long long i = 0; i < n; i++) {
		scanf("%lld", a + i);
		a[i]--;
	}
	y = -1; z = -1;
	while (z < 0) {
		s++;
		c[x]++;
		if (c[x] == 2 && y < 0)y = s;
		if (c[x] == 3 && z < 0)z = s;
		x = a[x];
	}
	if (k > n) {
		k %= (z - y);
		while (k < n)k += (z - y);
	}
	x = 0;
	for (int i = 0; i < k; i++) {
		x = a[x];
	}
	printf("%lld\n", x + 1);
}
