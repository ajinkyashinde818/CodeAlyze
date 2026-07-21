#include "bits/stdc++.h"
using namespace std;
vector<int>pops;
struct edge {
	int from;
	int to;
	long long int cost;
};
struct aa {
	edge frome;
	long long int cost;
	 int time;
};
class Compare {
public:
	bool operator()(const aa l, const aa r) {
		return l.cost == r.cost ?l.time==r.time?pops[l.frome.from] > pops[r.frome.from]: l.time > r.time:l.cost > r.cost;
	}
}comp;	


class Tree {
public:
	Tree(int V, int root) : V(V),revT(V), root(root), cnum(V), place(V), id(V) {
		T.resize(V);
		for (int i = 0; i < MAXLOGV; i++) {
			parent[i].resize(V);
			costs[i].resize(V);

		}
		depth.resize(V);
	}
	// u??¨v????????????
	// lca????±????????????¨????????????????????§????????°????????¨????????????
	void unite(edge& v) {
		T[v.from].push_back(v);
		revT[v.to]=(edge{ v.to,v.from,v.cost });
	}
	// init??????
	// ????????????????????????????????????????????????????????°????????¨lca????±???????????????????
	void init() {
		dfs(root, 0, 0);
		int id = 0;
		getid(root, 0, id);
	}
	// u??¨v???lca????±???????
	int lca(int u, int v) const {
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k < MAXLOGV; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v) return u;
		for (int k = MAXLOGV - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
	// u??¨v????????¢????±???????
	// edge????????????????????¨????????????????????????????????????
	int dist(int u, int v) const {
		int p = lca(u, v);
		return (depth[u] - depth[p]) + (depth[v] - depth[p]);
	}
	int dfs(int v, int p, int d) {
		parent[0][v] = p;
		costs[0][v] = revT[v].cost;
		depth[v] = d;
		cnum[v] = 0;
		for (int i = 1; i < MAXLOGV; i++) {
			parent[i][v] = parent[i - 1][parent[i - 1][v]];
			costs[i][v] = costs[i - 1][parent[i - 1][v]] + costs[i - 1][v];
		}
		for (auto e : T[v]) {
			int next = e.to;
			if (next != p) cnum[v] += dfs(next, v, d + 1);
		}
		return cnum[v] + 1;
	}

	void getid(const int v, const int p, int &nplace) {
		place[v] = nplace;
		id[nplace] = v;
		nplace++;
		for (auto e : T[v]) {
			int next = e.to;
			if (next != p) getid(next, v, nplace);
		}
	}
	static const int MAXLOGV = 20;
	// ??°???????????£??\???????????¨???
	vector<vector<edge> > T;
	vector<edge>revT;
	// ???????????°
	int V;
	// ?????????????????????
	int root;

	// ????????????
	vector<int> parent[MAXLOGV];
	vector<long long int>costs[MAXLOGV];
	// ??????????????±???
	vector<int> depth;

	//????????°
	vector<int>cnum;

	//??????
	vector<int>place;
	vector<int>id;

};

int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		pops.push_back(a);
	}
	vector<vector<edge>>edges(N);
	for (int i = 0; i < M; ++i) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		edges[a].push_back(edge{ a,b,c });
		edges[b].push_back(edge{ b,a,c });
	}
	
	vector<aa>memo(N, aa{ edge{-1,-1,-1},static_cast<long long int>(1e18),(static_cast<int>(1e9)) });
	memo[0] = aa{ edge{-1,0,0},0,0 };
	priority_queue<aa, vector<aa>, Compare>que;
	que.push(aa{ edge{-1,0,0},0,0 });
	while (!que.empty()) {
		aa atop(que.top());
		que.pop();
		for (auto e : edges[atop.frome.to]) {
			const int next = e.to;
			const long long int nextcost = atop.cost + e.cost;
			const int nexttime = atop.time + 1;
			if (comp.operator()(memo[next],aa{ e,nextcost,nexttime })) {
				memo[next] = aa{ e,nextcost,nexttime };
				que.push(aa{ e,nextcost,nexttime });
			}
		}
	}
	Tree t(N,0);
	for (int i = 1; i < N; ++i) {
		t.unite(memo[i].frome);
	}
	t.init();
	int K; cin >> K;
	for (int i = 0; i < K; ++i) {
		long long int sum = 0;
		int x, d, p; cin >> x >> d >> p;
		x--;
		if (d >= t.depth[x]) {
			int rest = t.depth[x];
			long long int need = 0;
			int now = x;
			for (int i = 0; i < 20; ++i) {
				if (rest&(1 << i)) {
					need += t.costs[i][now];
					now = t.parent[i][now];
				}
			}
			sum += max(0ll, need -p);
		}
		else {
			int rest = t.depth[x] - d;
			long long int need = 0;
			int now = x;
			for (int i = 0; i < 20; ++i) {
				if (rest&(1 << i)) {
					need += t.costs[i][now];
					now = t.parent[i][now];
				}
			}
			sum += need;
			rest = d;
			need = 0;
			for (int i = 0; i < 20; ++i) {
				if (rest&(1 << i)) {
					need += t.costs[i][now];
					now = t.parent[i][now];
				}
			}
			sum += max(0ll, need - p);
		}
		cout << sum << endl;
	}
	return 0;
}
