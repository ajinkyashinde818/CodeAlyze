//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <list>
#include <random>
#include <ctime>
#include <cmath>
#include <random>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ld, ld> pld;
typedef complex<double> base;

#define mmin(a, b) a = min(a, (b))
#define mmax(a, b) a = max(a, (b))
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ALL(a) a.begin(),a.end()
#define sqr(x) (x) * (x)
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define cint const int & 
#define SZ(a) ((int)(a.size()))
#define watch(x) cout << (#x) << " = " << x << endl;

const double PI = 2 * acos(0.0);

template<class T>
void show(const vector<T> &a) {
	for (T x : a)
		cout << x << " ";
	cout << endl;
}

const int N = 2e5 + 9;
const ll oo = 1e18;
int t[N << 2];
int pushing[N << 2];
int n;
int xx[N];
int vv[N];
ll sumvv[N];

void build(int v, int tl, int tr) {
	pushing[v] = 0;
	if (tl == tr) {
		if (tl < n) t[v] = 0;
		else t[v] = sumvv[tl - n] - xx[tl - n];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

void push(int v) {
	if (!pushing[v]) return;
	pushing[v << 1] += pushing[v];
	t[v << 1] += pushing[v];
	pushing[v << 1 | 1] += pushing[v];
	t[v << 1 | 1] += pushing[v];
	pushing[v] = 0;
}

ll get(int v, int tl, int tr, int l, int r) {
	if (l > r) return -oo;
	if (tl == l && tr == r) return t[v];
	push(v);
	int tm = (tl + tr) >> 1;
	return max(get(v << 1, tl, tm, l, min(tm, r)),
		get(v << 1 | 1, tm + 1, tr, max(tm + 1, l), r)
	);
}

void upd(int v, int tl, int tr, int l, int r, ll add) {
	if (l > r) return;
	if (tl == l && tr == r) {
		t[v] += add;
		pushing[v] += add;
		return;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	upd(v << 1, tl, tm, l, min(tm, r), add);
	upd(v << 1 | 1, tm + 1, tr, max(tm + 1, l), r, add);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll c;
	cin >> n >> c;

	fori (i, n)
		cin >> xx[i] >> vv[i];
	sumvv[0] = vv[0];
	for (int i = 1; i < n; ++i)
		sumvv[i] = vv[i] + sumvv[i - 1];
	build(1, 0, n << 1);
	ll ans = 0;
	mmax(ans, get(1, 0, n << 1, n, n + n - 1));
	//watch(ans);
	for (int i = n - 1; i >= 0; --i) {
		ll add = c - xx[i];
		if (i != n - 1) add = xx[i + 1] - xx[i];
		add <<= 1;
		upd(1, 0, n << 1, i + 1, i + 1 + n, -add);
		upd(1, 0, n << 1, i, i + n, vv[i]);
		ll cur = get(1, 0, n << 1, n, i + n - 1);
		mmax(cur, vv[i] - add);
		mmax(ans, cur);
	}

	//watch(ans);
	reverse(xx, xx + n);
	reverse(vv, vv + n);
	for (int i = 0; i < n; ++i) {
		xx[i] = c - xx[i];
		//cout << "xx[" << i << "] = " << xx[i] << endl;
		//watch(vv[i]);
	}

	sumvv[0] = vv[0];
	for (int i = 1; i < n; ++i) {
		sumvv[i] = vv[i] + sumvv[i - 1];
		//watch(sumvv[i]);
	}
	build(1, 0, n << 1);

	mmax(ans, get(1, 0, n << 1, n, n + n - 1));
	//watch(ans);
	for (int i = n - 1; i >= 0; --i) {
		ll add = c - xx[i];
		if (i != n - 1) add = xx[i + 1] - xx[i];
		add <<= 1;
		upd(1, 0, n << 1, i + 1, i + 1 + n, -add);
		upd(1, 0, n << 1, i, i + n, vv[i]);
		ll cur = get(1, 0, n << 1, n, i + n - 1);
		mmax(cur, vv[i] - add);
		mmax(ans, cur);
	}

	cout << ans << endl;
}
