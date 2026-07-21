#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, neg = 0;
	vector<ll> a;
	ll ans = 0;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) neg++, a[i] *= -1;
		ans += a[i];
	}
	sort(a.begin(), a.end());
	if (neg & 1) ans -= a[0] << 1LL;
	cout << ans << "\n";
	return 0;
}
