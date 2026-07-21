#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	ll n, c;
	cin >> n >> c;
	vector<ll> x(n), v(n);
	rep(i, n) cin >> x[i] >> v[i];
	ll ans = 0;
	ll sum = 0;
	vector<ll> rot(n);
	rep(i, n) {
		sum += v[i];
		if (i == 0) rot[i] = max(sum - x[i], 0LL);
		else rot[i] = max(sum - x[i], rot[i - 1]);
	}
	chmax(ans, rot[n - 1]);
	ll sum2 = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum2 += v[i];
		ll val = sum2 - (c - x[i]) * 2;
		if (i > 0) val += rot[i - 1];
		chmax(ans, val);
	}
	rep(i, n) x[i] = c - x[i];
	reverse(all(x)); reverse(all(v));
	ll sum3 = 0;
	vector<ll> rot2(n);
	rep(i, n) {
		sum3 += v[i];
		if (i == 0) rot2[i] = max(sum3 - x[i], 0LL);
		else rot2[i] = max(sum3 - x[i], rot2[i - 1]);
	}
	chmax(ans, rot2[n - 1]);
	ll sum4 = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum4 += v[i];
		ll val = sum4 - (c - x[i]) * 2;
		if (i > 0) val += rot2[i - 1];
		chmax(ans, val);
	}
	cout << ans << '\n';
}
