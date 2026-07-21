#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> accum(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		ll a; cin >> a;
		accum[i] += a;
		accum[i] += accum[i - 1];
	}
	ll ans = 9223372036854775807LL;
	for (ll i = 1; i <= n - 1; i++) {
		ll left = accum[i];
		ll right = accum[n] - accum[i];
		ll tmp = abs(left - right);
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}
