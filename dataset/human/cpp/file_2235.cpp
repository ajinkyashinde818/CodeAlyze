#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n);
	ll minusCnt = 0;
	ll minAbsValue = 10000000000;
	ll sum = 0;
	ll ans;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		sum += abs(a[i]);
		if (a[i] < 0) minusCnt++;
		minAbsValue = min(minAbsValue, abs(a[i]));
	}
	if (minusCnt % 2 == 0) ans = sum;
	else {
		ans = sum - 2 * minAbsValue;
	}
	cout << ans << endl;
	return 0;
}
