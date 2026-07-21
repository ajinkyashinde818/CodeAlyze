#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll pr[200500];
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pr[i + 1] = x + pr[i];
	}
	ll ans = LONG_MAX;
	for (int i = 1; i <= n - 1; i++) {
		ans = min(ans, abs(pr[i] - pr[n] + pr[i]));
	}
	cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
	int T = 1; 
    //cin >> T;
    while(T--) solve();
}
