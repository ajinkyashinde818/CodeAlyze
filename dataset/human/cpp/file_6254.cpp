#include <iostream>
#include <set>
using namespace std;
using ll = long long;

ll dp[205][205];

ll grundy(ll w, ll b) {

	if (dp[w][b] != -1) return dp[w][b];
	set<ll> s;

	if (w - 1 >= 0) s.insert(grundy(w - 1, b));
	if (b - 1 >= 0) s.insert(grundy(w + 1, b - 1));

	for (int i = 1; i <= w; i++) {
		if (b - i >= 0) s.insert(grundy(w, b - i));
	}

	ll g = 0;
	while (s.find(g) != s.end()) g++;

	return dp[w][b] = g;
}

int main() {
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= 200; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			grundy(i, j);
		}
	}

	ll n;
	ll w, b;
	ll x = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w >> b;
		x ^= grundy(w, b);
	}

	if (x != 0) cout << 0 << endl;
	else cout << 1 << endl;
}
