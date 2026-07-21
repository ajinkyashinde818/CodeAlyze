#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int u32;
typedef pair<int, int> p;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int Inf = (1<<30);
ll inf = (1LL<<60);
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main() {
	int n;
	cin >> n;
	int i;
	vector<int> a(n + 1);
	ll sum = 0;
	vector<ll> Lsum(n + 1);
	vector<ll> Rsum(n + 1);
	Lsum[0] = 0;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		Lsum[i] = Lsum[i - 1] + a[i];
		sum += a[i];
	}
	for (i = 1; i <= n; i++) {
		Rsum[i] = sum - Lsum[i];
	}
	ll ans = inf;
	for (i = 1; i < n; i++) {
		ans = min(ans, abs(Lsum[i] - Rsum[i]));
	}
	cout << ans;
	return 0;
}
