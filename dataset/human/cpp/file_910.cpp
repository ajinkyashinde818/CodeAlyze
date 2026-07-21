#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

int r, g, b, n;
int main() {
	std::cin >> r >> g >> b >> n;

	ll ans = 0;
	for (int i = 0, end = n / r; i <= end; ++i) {
		for (int j = 0, end2 = n / g; j <= end2; ++j) {
			auto s = n - (r * i + g * j);
			if (s >= 0 && s % b == 0)
				++ans;
		}
	}

	std::cout << ans << std::endl;
	return 0;
}
