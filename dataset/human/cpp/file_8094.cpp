#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod = 1e9 + 7;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	int n;
	cin >> n;

	vector<int> vi(n);
	ll sum = 0;
	ll ans = 1e20;

	for (int i = 0; i < n; i++) {
		cin >> vi[i];
		sum += vi[i];
	}
	
	ll now = 0;
	for (int i = 0; i < n; i++) {
		now += vi[i];
		if (i + 1 < n) {
			ans = min(ans, abs(sum - 2 * now));
		}
	}

	cout << ans << endl;
}
