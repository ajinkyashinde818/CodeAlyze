#include <stdio.h>

int factorize(long long n, long long p[], int m[])
{
	int k;
	long long i;
	for (i = 2, k = 0; i * i <= n; i++) {
		if (n % i != 0) continue;
		p[k] = i;
		for (m[k] = 0; n % p[k] == 0; m[k]++, n /= p[k]);
		k++;
	}
	if (n > 1) {
		p[k] = n;
		m[k++] = 1;
	}
	return k;
}

int main()
{
	long long N;
	scanf("%lld", &N);
	
	long long p[100];
	int i, j, m[100], k = factorize(N, p, m), ans = 0;
	for (i = 0; i < k; i++) {
		for (j = 0; j * (j + 1) <= m[i] * 2; j++);
		ans += j - 1;
	}
	printf("%d\n", ans);
	fflush(stdout);
	return 0;
}
