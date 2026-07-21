#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const double PI = 3.1415926535897932384626433832795;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : abs(x); }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll r, g, b, n;
	cin >> r >> g >> b >> n;

	ll ans = 0;
	for (ll rr = 0; rr <= n; rr += r) {
		for (ll gg = 0; gg <= n; gg += g) {
			ll bb = n - (rr + gg);

			if (bb < 0LL || bb > n || (bb % b != 0LL)) {
				continue;
			}

			ll score = rr + gg + bb;
			ans += (score == n);
		}
	}

	cout << ans << endl;
	return 0;
}
