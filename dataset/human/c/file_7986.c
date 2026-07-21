#include <stdio.h>

#define MAX 1000000
const int MOD = 1e9+7;

long long int fac[MAX], finv[MAX], inv[MAX];

// 前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i-1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i-1] * inv[i] % MOD;
	}
}

long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	int X, Y;
	scanf("%d %d", &X, &Y);
	COMinit();
	if ((X + Y) % 3 != 0) printf("0\n");
	else {
		int cnt_1 = X, cnt_2 = 0;
		while (2*cnt_1 + 1* cnt_2 != Y) {
			cnt_1 -= 2;
			cnt_2 += 1;
		}
		printf("%lld\n", COM(cnt_1 + cnt_2, cnt_1));
	}
	return 0;
}
