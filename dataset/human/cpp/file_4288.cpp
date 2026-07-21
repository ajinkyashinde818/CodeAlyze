#include <bits/stdc++.h>
using namespace std;
const int MAX = (1e5)+1;

int n, xora, xorb, a[MAX], b[MAX], dsu[MAX], cnt[MAX];
vector<int> tmpa, tmpb;
map<int,int> compress;
int root(int v) { return (dsu[v] < 0 ? v : dsu[v] = root(dsu[v])); }
void merge(int u, int v) {
	if((u = root(u)) == (v = root(v))) {
		cnt[u]++;
		return;
	}
	if(dsu[u] > dsu[v]) swap(u, v);
	dsu[u] += dsu[v];
	dsu[v] = u;
	cnt[u] += cnt[v]+1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(dsu, dsu+MAX, -1);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		tmpa.push_back(a[i]);
		xora ^= a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		tmpb.push_back(b[i]);
		xorb ^= b[i];
	}
	a[n] = xora;
	b[n] = xorb;
	tmpa.push_back(xora);
	tmpb.push_back(xorb);
	sort(tmpa.begin(), tmpa.end());
	sort(tmpb.begin(), tmpb.end());
	for(int i = 0; i <= n; i++) if(tmpa[i] != tmpb[i]) cout << -1, exit(0);
	tmpa.resize(distance(tmpa.begin(), unique(tmpa.begin(), tmpa.end())));
	for(int i = 0; i < tmpa.size(); i++) compress[tmpa[i]] = i;
	for(int i = 0; i <= n; i++) {
		a[i] = compress[a[i]];
		b[i] = compress[b[i]];
		if(a[i] != b[i]) merge(a[i], b[i]);
	}
	int ans = cnt[root(a[n])] - (a[n] != b[n]);
	for(auto p: compress) if(root(p.second) == p.second && root(p.second) != root(a[n]) && cnt[root(p.second)]) ans += cnt[root(p.second)]+1;
	cout << ans;
}
