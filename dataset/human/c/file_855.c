#include <stdio.h>
#include <string.h>

using ll  = long long;

int main()
{
	ll N;
	scanf("%lld", &N);

	ll ans = 0;
	ll p = 2;
	while (p * p <= N) {
		ll count = 0;
		while (N % p == 0) {
			N /= p;
			count++;
		}
		ll tmpans = 0;
		for (ll i = 1; i <= count; i++) {
			count -= i;
			tmpans++;
		}
		ans += tmpans;
		p++;
	}
	if (N > 1) {
		ans++;
	}

	printf("%lld\n", ans);

	return 0;
}
