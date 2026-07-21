#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#define DIV 1000000007

//高速べき乗(mod DIV)
long long mypow(long long k, long long n) {
	long long temp = 1;

	k = k % DIV;
	while (n) {
		if (n % 2) temp = temp * k % DIV;
		k = k * k % DIV;
		n = n / 2;
	}
	return temp % DIV;
}

//組み合わせ(mod DIV)
long long cmb(long long n, long long r) {
	long long x = 1, y = 1, y_inv;
	long long min;

	if (n - r > r) min = r;
	else min = n - r;
	for (long long i = 0; i < min; i++) {
		x = x * (n - i) % DIV;
		y = y * (i + 1) % DIV;
	}
	y_inv = mypow(y, DIV - 2);
	return x * y_inv % DIV;
}
int main(void) {
	long long x, y;
	long long a = -1, b = -1;
	long long ans = 0;

	scanf("%lld %lld", &x, &y);
	if (2 * y - x < 0 || 2 * x - y < 0) printf("0");
	else {
		if ((2 * y - x) % 3 == 0)a = (2 * y - x) / 3;
		if ((2 * x - y) % 3 == 0)b = (2 * x - y) / 3;

		if (a == -1 || b == -1)printf("0");
		else {
			ans = cmb(a + b, a);
			printf("%lld", ans);
		}
	}
	return 0;
}
