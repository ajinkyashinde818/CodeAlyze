#include<bits/stdc++.h>
using namespace std;

const int N = 1000 * 100 + 10;
int a[N], b[N], n, par[N * 2], sz[N * 2];

int get_par(int root) {
	return par[root] == root? root: par[root] = get_par(par[root]);
}

void Union(int v, int u) {
	v = get_par(v), u = get_par(u);
	if (v == u)
		return;
	if (sz[u] > sz[v])
		swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
}

int main() { 
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], a[n] ^= a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i], b[n] ^= b[i];
	map<int, int> cnt;
	for (int i = 0; i <= n; i++)
		cnt[a[i]]++;
	for (int i = 0; i < n; i++) {
		cnt[b[i]]--;
		if (cnt[b[i]] < 0)
			return cout << "-1\n", 0;
	}
	vector<int> vec;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			vec.push_back(a[i]), vec.push_back(b[i]), ans++;
	vec.push_back(a[n]), vec.push_back(b[n]);
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	int s = (int)(vec.size());
	for (int i = 0; i < s; i++)
		par[i] = i, sz[i] = 1;
	for (int i = 0; i <= n; i++) 
		if (a[i] != b[i]) {
			a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
			b[i] = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin();
			Union(a[i], b[i]);
		}
	for (int i = 0; i < s; i++)
		if (get_par(i) == i)
			ans++;
	cout << ans - 1 << '\n';
	return 0;
}
