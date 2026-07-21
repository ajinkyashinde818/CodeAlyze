// abc067_c.cc
#include <bits/stdc++.h>
using namespace std;

int main() {
	using ll = long long;
	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		a[i] = sum;
	}

	ll ans = LLONG_MAX;
	for (int i = n - 1; i > 0; i--) {
		ll x = a.back() - a[i - 1];
		ll y = a[i - 1];
		ans = min(ans, abs(x - y));
	}

	cout << ans << "\n";

	return 0;
}
