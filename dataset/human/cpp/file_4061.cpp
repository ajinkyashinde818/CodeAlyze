// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;

#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline void setin(string s) {
	freopen(s.c_str(), "r", stdin);
}

inline void setout(string s) {
	freopen(s.c_str(), "w", stdout);
}

template <typename T> inline T range(T l, T r) {
	return uniform_int_distribution <T>(l, r)(rng);
}

template <typename T> void Min(T &a, T b) {
    a = min(a, b);
}
 
template <typename T> void Max(T &a, T b) {
    a = max(a, b);
}

struct pt {
	int x, y, r;
};

const ld inf = 2e18;
const ld eps = 1e-15;
const int mod = 1e9 + 7;
const int N = 1e3 + 15;
int n, m;
pt a[N];

inline ll sq(int x) {
	return 1ll * x * x;
}

ld d[N], g[N][N];

inline void add_edge(int u, int v) {
	ld dist = sqrt(sq(a[u].x - a[v].x) + sq(a[u].y - a[v].y));
	dist = max((ld)0, dist - a[u].r - a[v].r);
	g[u][v] = dist;
	// cout << u << ' ' << v << ' ' << g[u][v] << endl;
}

bool used[N];

inline bool ls(ld a, ld b) {
	return a - b > eps;
}

main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	// setin("input.txt");
	cin >> a[1].x >> a[1].y >> a[2].x >> a[2].y;
	a[1].r = a[2].r = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i+2].x >> a[i+2].y >> a[i+2].r;
	n += 2;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			add_edge(i, j);
	fill(d, d + N, inf);
	d[1] = 0;
	while(1) {
		int v = -1;
		for(int i = 1; i <= n; ++i)
			if(!used[i] && (v == -1 || d[i] < d[v]))
				v = i;
		if(v == -1)
			break;
		used[v] = true;
		for(int to = 1; to <= n; ++to)
			if(ls(d[to], d[v] + g[v][to]))
				d[to] = d[v] + g[v][to];
	}
	// for(int i = 1; i <= n; ++i)
	// 	cout << d[i] << ' ';
	// cout << endl;
	// assert(used[2]);
	cout.precision(30);
	cout << d[2] << endl;
	return 0;
}
