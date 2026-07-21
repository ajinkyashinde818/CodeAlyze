#include <stdio.h>
#define N 1000000
#define MOD 1000000007
typedef long long ll;

ll fac[N], finv[N], inv[N];

void cminit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < N; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

ll cmb(int n, int k) {
	if (n < k)
		return 0;
	if (n < 0 || k < 0)
		return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(void) {
	int x, y;
	scanf("%d%d", &x, &y);

	if ((x + y) % 3 != 0) {
		printf("0\n");
		return 0;
	}

	int m = x - (x + y) / 3;
	int n = y - (x + y) / 3;
	if (n < 0 || m < 0) {
		printf("0\n");
		return 0;
	}

	cminit();

	printf("%lld\n", cmb(n + m, n));
	return 0;
}
