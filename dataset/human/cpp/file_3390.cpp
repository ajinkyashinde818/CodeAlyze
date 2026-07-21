#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

int n;
ll a[100005];
int main() {
	std::cin >> n;

	int num = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		if (a[i] < 0)
			++num;
		a[i] = std::abs(a[i]);
	}

	ll ans = 0;
	if (num % 2 == 0) {
		for (int i = 0; i < n; ++i)
			ans += a[i];
	}
	else {
		std::sort(a, a + n);
		ans = -a[0];
		for (int i = 1; i < n; ++i)
			ans += a[i];
	}

	std::cout << ans << std::endl;
	return 0;
}
