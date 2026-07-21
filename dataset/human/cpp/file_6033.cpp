#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr int iinf = static_cast<int>(1e9);
constexpr ll mod = static_cast<ll>(1e9 + 7);
constexpr long long MOD(long long in) {
	return in % mod;
}

int n;
ll c;
ll x[100005], v[100005];
std::pair<ll, ll> dp[100005], dp2[100005];
int main()
{
	std::cin >> n >> c;

	for (int i = 1; i <= n; i++)
		std::cin >> x[i] >> v[i];

	ll vsum = 0;
	for (int i = 1; i <= n; i++) {
		vsum += v[i];

		if (dp[i - 1].first < vsum - x[i])
			dp[i].second = x[i];
		else
			dp[i].second = dp[i - 1].second;
		dp[i].first = std::max(dp[i - 1].first, vsum - x[i]);
	}

	vsum = 0;
	for (int i = n; i >= 1; i--) {
		vsum += v[i];

		if (dp2[i + 1].first < vsum - (c - x[i]))
			dp2[i].second = c - x[i];
		else
			dp2[i].second = dp2[i + 1].second;
		dp2[i].first = std::max(dp2[i + 1].first, vsum - (c - x[i]));
	}

	ll ans = 0;
	for (int i = 0; i <= n; ++i)
		ans = std::max(ans, dp[i].first + dp2[i + 1].first - std::min(dp[i].second, dp2[i + 1].second));

	std::cout << ans << std::endl;
	return 0;
}
