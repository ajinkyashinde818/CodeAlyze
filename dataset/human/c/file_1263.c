#include <stdio.h>

#define Mod 1000000007

long long div_mod(long long x, long long y, long long z)
{
	if (x % y == 0) return x / y;
	else return (div_mod((1 + x / y) * y - x, (z % y), y) * z + x) / y;
}

int main()
{
	int i, N, x[100001];
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &(x[i]));
	
	long long fact[100001], ans = 0, sum = 0;
	for (i = 1, fact[0] = 1; i < N; i++) fact[i] = fact[i-1] * i % Mod;
	for (i = 1; i < N; i++) fact[i] = div_mod(fact[N-1], (long long)i, Mod);
	for (i = 1; i < N; i++) {
		sum = (sum + fact[i]) % Mod;
		ans = (ans + sum * (x[i+1] - x[i])) % Mod;
	}
	
	printf("%lld\n", ans);
	fflush(stdout);
	return 0;
}
