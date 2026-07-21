// abc125_d.cc
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	using ll = long long;

	int n, cnt = 0;
	cin >> n;

	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt += a[i] < 0;
		a[i] = abs(a[i]);
	}

	sort(a.begin(), a.end());
	ll ans = (cnt % 2 == 1) ? -a[0] : 0;
	for (int i = (cnt % 2 == 1) ? 1 : 0 ; i < n; i++) {
		ans += a[i];
	}

	cout << ans << "\n";
}
