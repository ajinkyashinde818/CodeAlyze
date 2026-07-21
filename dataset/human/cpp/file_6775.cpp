#include "bits/stdc++.h"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using ll = long long int;

const int mod = 1e9+7;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n; cin >> n;
	map<int, int> m;
	vector<int> a(n), b(n);
	for (auto &i : a) {
		cin >> i;
		++m[i];
	}
	for (auto &i : b) {
		cin >> i;
		++m[i];
	}
	for (auto [x, y] : m)
		if (y > n) return cout << "No\n", 0;
	reverse(begin(b), end(b));
	int l = 0, r = -1, intersect = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) continue;
		intersect = a[i];
		if (r == -1) l = i;
		r = i;
	}
	set<int> active;
	for (int i = 0; i < n; ++i) {
		if (a[i] == intersect || b[i] == intersect) continue;
		active.insert(i);
	}
	for (int i = l; i <= r; ++i) {
		auto u = *active.begin();
		swap(b[i], b[u]);
		active.erase(u);
	}
	cout << "Yes\n";
	for (auto x : b)
		cout << x << ' ';
}
