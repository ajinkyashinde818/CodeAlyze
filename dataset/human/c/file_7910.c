#include <stdio.h>

long long gcd(long long a, long long b)
{
	if (a > b) {
		a ^= b;
		b ^= a;
		a ^= b;
	}
	if (b % a == 0) return a;
	else return gcd(b % a, a);
}

int main()
{
	int i, N;
	long long M, a[100001];
	scanf("%d %lld", &N, &M);
	for (i = 1; i <= N; i++) scanf("%lld", &(a[i]));
	
	long long g = a[1], l, b;
	for (i = 2; i <= N; i++) g = gcd(g, a[i]);
	for (b = 2; (g & b) == 0; b <<= 1);
	for (i = 1, l = b >> 1; i <= N; i++) {
		a[i] /= b;
		if (a[i] % 2 == 0) break;
		l *= a[i] / gcd(a[i], l);
		if (l > M) break;
	}
	
	if (i <= N) printf("0\n");
	else printf("%lld\n", (M + l) / l / 2);
	fflush(stdout);
	return 0;
}
