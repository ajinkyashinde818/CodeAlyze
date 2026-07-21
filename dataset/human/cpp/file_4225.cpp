#include <bits/stdc++.h>

using namespace std;

long long n, ans;

int main() {
	scanf("%lld", &n);
	if (n == 0) {
		puts("0");
	} else {
		n--;
		ans++;
		ans += n % 3;
		n /= 3;
		while (n) {
			long long tmp = min(2LL, n);
			n -= tmp;
			ans += tmp;
			ans += n % 3;
			n /= 3;
		}
		printf("%lld\n", ans);
	}
}
