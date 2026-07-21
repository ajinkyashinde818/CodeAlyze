#include <bits/stdc++.h>

typedef long long ll;
const int MAX_N = 200000;
const ll INF = (ll) 2e+18;

int main() {
	int N;
	static ll sum[MAX_N] = {};

	std::cin >> N;
	ll s = 0;
	for(int i = 0; i < N; ++i) {
		ll a;
		std::cin >> a;
		s += a;
		sum[i] = s;
	}

	ll ans = INF;
	for(int i = 0; i < N - 1; ++i) {
		ans = std::min(ans, std::abs(sum[N - 1] - 2 * sum[i]));
	}

	std::cout << ans << std::endl;
}
