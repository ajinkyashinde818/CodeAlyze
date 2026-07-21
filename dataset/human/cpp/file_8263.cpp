#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> G[100009]; int root = 0, parent[17][100009], depth[100009];
void dfs(int v, int p, int d) {
	parent[0][v] = p; depth[v] = d;
	for (int i : G[v]) if (i != p) dfs(i, v, d + 1);
}
void init(int v) {
	dfs(root, -1, 0);
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < v; j++) {
			if (parent[i][j] < 0) parent[i + 1][j] = -1;
			else parent[i + 1][j] = parent[i][parent[i][j]];
		}
	}
}
int query(int v1, int v2) {
	if (depth[v1] > depth[v2]) swap(v1, v2);
	for (int i = 0; i < 17; i++) {
		if ((depth[v2] - depth[v1]) >> i & 1) v2 = parent[i][v2];
	}
	if (v1 == v2) return v1;
	for (int i = 16; i >= 0; i--) {
		if (parent[i][v1] != parent[i][v2]) {
			v1 = parent[i][v1];
			v2 = parent[i][v2];
		}
	}
	return parent[0][v1];
}
int n, p;
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> p; p--;
		G[p].push_back(i);
		G[i].push_back(p);
	}
	for (int i = 0; i < n; i++) {
		sort(G[i].begin(), G[i].end());
	}
	init(n);
	queue<int> que; que.push(0);
	long long ret = 0; int prev_ = 0;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i : G[u]) {
			if (i < u) continue;
			int a = query(prev_, i);
			ret += depth[prev_] + depth[i] - depth[a] * 2;
			prev_ = i;
			que.push(i);
		}
	}
	cout << ret << endl;
	return 0;
}
