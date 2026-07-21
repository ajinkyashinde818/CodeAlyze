#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
vector<int> G[100000];
int root;
int parent[17][100000];
int depth[100000];
void dfs(int v, int p, int d) {
	parent[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < (int)G[v].size(); i++) {
		if (G[v][i] != p)dfs(G[v][i], v, d + 1);
	}
}
void init(int V) {
	dfs(root, -1, 0);
	for (int k = 0; k + 1 < 17; k++) {
		for (int v = 0; v < V; v++) {
			if (parent[k][v] < 0)parent[k + 1][v] = -1;
			else parent[k + 1][v] = parent[k][parent[k][v]];
		}
	}
}
int lca(int u, int v) {
	if (depth[u] > depth[v])swap(u, v);
	for (int k = 0; k < 17; k++) {
		if ((depth[v] - depth[u]) >> k & 1) {
			v = parent[k][v];
		}
	}
	if (u == v)return u;
	for (int k = 16; k >= 0; k--) {
		if (parent[k][u] != parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}
int main() {
	int n; cin >> n;
	rep1(i, n - 1) {
		int p; cin >> p; p--; G[p].push_back(i);
	}
	root = 0;
	init(n);
	ll sum = 0;
	vector<int> v;
	rep(i, n) {
		if (depth[i] == 1)v.push_back(i);
	}
	sort(v.begin(), v.end());
		queue<int> q;
	rep(i, (int)v.size()) {
		q.push(v[i]);
	}
	int now = 0;
	while (!q.empty()) {
		int id = q.front(); q.pop();
		int pp = lca(now, id);
		sum += depth[now] + depth[id] - 2 * depth[pp];
		now = id;
		rep(j, (int)G[id].size()) {
			q.push(G[id][j]);
		}
	}
	cout << sum << endl;
	return 0;
}
