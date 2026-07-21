#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	array<ll, 2> dp = {0, -INF};
	for (int i = 0; i < N; i++) {
		ll v; cin >> v;
		array<ll, 2> ndp = {-INF, -INF};
		for (int a = 0; a < 2; a++) {
			for (int b = 0; b <= int(i < N-1); b++) {
				ndp[b] = max(ndp[b], dp[a] + v * ((a + b) % 2 ? -1 : 1));
			}
		}
		dp = move(ndp);
	}
	ll ans = dp[0];
	cout << ans << '\n';

	return 0;
}
