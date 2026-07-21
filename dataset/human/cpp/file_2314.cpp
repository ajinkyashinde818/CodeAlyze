#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long inf = 100000000000000;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int nCr(int n, int r) {
	int ans = 1;
	for (int i = n; i > n - r; --i) {
		ans = ans * i;
	}
	for (int i = 1; i < r + 1; ++i) {
		ans = ans / i;
	}
	return ans;
}
bool is_even(ll x) {return x % 2==0 ? 1 : 0; }
int main() {
	int n;
	cin >> n;
	ll a[110000];
	int i;
	int mainasu = 0;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) {
			mainasu++;
		}
	}
	ll ans = 0;
	ll mini = inf;
	int cheak;
	if (is_even(mainasu)) {
		for (i = 0; i < n; i++) {
			ans += abs(a[i]);
		}
	}
	else {
		for (i = 0; i < n; i++) {
			ans += abs(a[i]);
			mini = min(mini, abs(a[i]));
		}
	}
	if (is_even(mainasu)) cout << ans;
	else cout << ans - mini * 2;
	return(0);
}
