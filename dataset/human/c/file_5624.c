#include <stdio.h>
typedef long long ll;
int main() {
	ll x, ans;
	scanf("%lld", &x);
	ans = (x / (5 + 6)) * 2;
	int left = x % (5 + 6);
	if (left == 0) {
		ans += 0;
	} else if (1 <= left && left <= 6) {
		ans += 1;
	} else {
		ans += 2;
	}
	printf("%lld\n", ans);
	return 0;
}
