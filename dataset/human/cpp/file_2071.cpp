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

ll solve(int n, const vector<ll> &a) {
	vector<ll> abses = a;
	transform(begin(abses), end(abses), begin(abses), [](ll v) { return abs(v); });
	ll sum = accumulate(begin(abses), end(abses), 0LL);

	ll minusCnt = accumulate(begin(a), end(a), 0LL, [](ll acc, ll v) { return acc + (v < 0LL); });
	if (minusCnt % 2LL == 0LL) {
		return sum;
	}


	ll mi = *min_element(begin(abses), end(abses));
	return sum -(2LL * mi);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> a(n);
	for (auto &v : a) {
		cin >> v;
	}

	ll ans = solve(n, a);
	cout << ans << endl;
	return 0;
}
