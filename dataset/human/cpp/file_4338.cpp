#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;

vector<ll>a, b;

struct UnionFind
{
	map<ll, ll> par;
	map<ll, int> sizes;

	UnionFind(int n){
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				sizes[a[i]] = 1;
				sizes[b[i]] = 1;

				par[a[i]] = a[i];
				par[b[i]] = b[i];
			}
		}
	}

	ll find(ll x) {
		if (x == par[x])return x;
		return par[x] = find(par[x]);
	}

	void unite(ll x, ll y) {
		x = find(x);
		y = find(y);

		if (x == y) return;

		if (sizes[x] < sizes[y]) swap(x, y);

		par[y] = x;
		sizes[x] += sizes[y];
	}

	bool same(ll x, ll y) {
		return find(x) == find(y);
	}

	int size(ll x) {
		return sizes[find(x)];
	}
};


int main()
{
	int N; cin >> N;
	a.resize(N);
	b.resize(N);
	for (int i = 0; i < N; i++)cin >> a[i];
	for (int i = 0; i < N; i++)cin >> b[i];

	ll ax = a[0];
	for (int i = 1; i < N; i++)ax ^= a[i];
	ll bx = b[0];
	for (int i = 1; i < N; i++)bx ^= b[i];

	int mode = 0;

	bool same = false;
	int cnt = 0;
	UnionFind uf(N);
	for (int i = 0; i < N; i++) {
		if (a[i] != b[i]) {
			cnt++;

			uf.unite(a[i], b[i]);

			mode = 1;
		}

		if (b[i] == ax)same = true;
	}

	int cut = 0;
	map<ll, bool>link;
	for (int i = 0; i < N; i++) {
		if (a[i] != b[i]) {
			if (link[uf.find(a[i])] == false) {
				cut++;
				link[uf.find(a[i])] = true;
			}
		}
	}

	a.push_back(ax);
	b.push_back(bx);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i <= N; i++) {
		if (a[i] != b[i]) {
			mode = -1;
			break;
		}
	}

	if (mode == 1) {
		cout << cnt + cut - 1 + !same << endl;
	}
	else cout << mode << endl;

    return 0;
}
