#include <stdio.h>

#define LIM 1000000
int sieve[LIM], primes[LIM], pcnt = 0;

int main(void) {
	long long int n;
	scanf("%lld", &n);

	sieve[0] = sieve[1] = 1;
	primes[pcnt++] = 2;
	for (int i = 3; (long long int) i*i <= n; i += 2) {
		if (sieve[i])
			continue;
		primes[pcnt++] = i;
		for (long long int j = (long long int) i*i; j < LIM; j += i)
			sieve[j] = 1;
	}

	int ans = 0;
	for (int i = 0; i < pcnt && n > 1; i++) {
		int cnt = 0;
		while (n % primes[i] == 0) {
			cnt++;
			n /= primes[i];
		}
		if (!cnt)
			continue;

		for (int j = 1; j <= cnt; j++) {
			cnt -= j;
			ans++;
		}
	}

	if (n > 1)
		ans++;
	printf("%d\n", ans);
}
