#include <math.h>
#include <stdio.h>
typedef long long ll;
int main() {
	ll n;
	ll ans = 0;
	scanf("%lld", &n);
	for (ll i = 2; i * i <= n; i++) {
		int cnt = 0;
		while (n % i == 0) {
			cnt++;
			n /= i;
		}
		// printf("%d\n", cnt);
		ans += (ll)(-1 + sqrt(1 + 8 * cnt)) / 2;
	}
	if (n == 1) {
		// printf("\b\b \n");
	} else {
		ans++;
	}
	printf("%lld\n", ans);
	return 0;
}
