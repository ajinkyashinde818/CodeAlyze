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
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000010;
constexpr ll INF = 1000000000000000010;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

class unionfind {
	vector<int> par;
	vector<int> sz;
public:
	unionfind(int n) {
		par = vector<int>(n);
		for (int i = 0; i < n; i++) par[i] = i;
		sz = vector<int>(n, 1);
	}
	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
	int si(int x) { return sz[find(x)]; }
	bool same(int x, int y) { return find(x) == find(y); }
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (sz[x] < sz[y]) {
			par[x] = y;
			sz[y] += sz[x];
		}
		else {
			par[y] = x;
			sz[x] += sz[y];
		}
	}
};

vector<int> shrink(vector<int> vec) {
	int vecsize = vec.size();
	vector<int> tmpvec = vec;
	sort(tmpvec.begin(), tmpvec.end());
	tmpvec.erase(unique(tmpvec.begin(), tmpvec.end()), tmpvec.end());
	vector<int> res(vecsize);
	for (int i = 0; i < vecsize; i++) res[i] = lower_bound(tmpvec.begin(), tmpvec.end(), vec[i]) - tmpvec.begin();
	return res;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	int suma = 0, sumb = 0;
	rep(i, n) {
		cin >> a[i];
		suma ^= a[i];
	}
	rep(i, n) {
		cin >> b[i];
		sumb ^= b[i];
	}
	vector<int> c = a, d = b;
	c.pb(suma); d.pb(sumb);
	sort(all(c)); sort(all(d));
	if (c != d) {
		cout << "-1\n";
		return 0;
	}
	a.pb(suma); b.pb(sumb);
	a = shrink(a); b = shrink(b);
	unionfind uni(100010);
	int ans = n;
	rep(i, n) {
		if (a[i] == b[i]) ans--;
		else uni.unite(a[i], b[i]);
	}
	uni.unite(a[n], b[n]);
	set<int> st;
	rep(i, n + 1) if (i == n || a[i] != b[i]) st.insert(uni.find(a[i]));
	cout << max(0, ans - 1 + (int)st.size()) << '\n';
}
