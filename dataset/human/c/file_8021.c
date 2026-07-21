/* Coached by rainboy */
#include <stdio.h>

#define N 1000000
#define MD 1000000007

long long power(int a, int b) {
	long long p;

	if (b == 0)
		return 1;
	p = power(a, b / 2);
	p = p * p % MD;
	if (b % 2)
		p = p * a % MD;
	return p;
}

int ff[N + 1], gg[N + 1];

int choose(int n, int k) {
	return (long long) ff[n] * gg[k] % MD * gg[n - k] % MD;
}

int main() {
	int x, y, a, b, i;
	long long f;

	scanf("%d%d", &x, &y);
	if ((x + y) % 3 || x * 2 < y || y * 2 < x) {
		printf("0\n");
		return 0;
	}
	f = 1;
	for (i = 0; i <= N; i++) {
		gg[i] = power(ff[i] = f, MD - 2);
		f = f * (i + 1) % MD;
	}
	a = (y * 2 - x) / 3, b = (x * 2 - y) / 3;
	printf("%d\n", choose(a + b, a));
	return 0;
}
