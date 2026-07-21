// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
int a[N], b[N], c[N], d[N];
map<int, int> par, sz;
int find(int x) {
	if (par.find(x) == par.end()) return par[x] = x;
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}
void unite(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	par[u] = v;
}
map<int, int> deg;
int main() {
	int n;
	cin >> n;
	int s0 = 0;
	for (int j = 0; j < n; ++j) cin >> a[j], s0 ^= a[j], c[j] = a[j];
	c[n] = s0;
	int s1 = 0;
	for (int j = 0; j < n; ++j) cin >> b[j], s1 ^= b[j], d[j] = b[j];
	d[n] = s1;
	++n;
	sort(d, d + n);
	sort(c, c + n);
	for (int j = 0; j < n; ++j)
		if (c[j] != d[j]) {
			cout << -1 << endl;
			return 0;
		}
	--n;
	set<int> all;
//	if (s0 != s1) unite(s0, s1);
	int res = 0;//flag = 0;
	for (int j = 0; j < n; ++j) {
		res += (a[j] != b[j]);
		if (a[j] != b[j]) {
			unite(a[j], b[j]);
		}
	}
	if (res == 0) {
		cout << 0 << endl;
		return 0;
	}
	unite(s0, s1);
	for (int j = 0; j < n; ++j)
		if (a[j] != b[j])
			all.insert(find(a[j]));
	all.erase(find(s0));
	cout << max(0, res + (int) all.size()) << endl;
	 
	 
}
