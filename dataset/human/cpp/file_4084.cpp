#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;

const int N = 1000 + 10;

struct P
{
	int x, y;
	void read() { cin >> x >> y; }
} c[N];

ld edges[N][N], cost_dijkstra[N];
bool vis[N];
int r[N], n;

struct node {
	int u;
	ld cost;
	node(int x, ld y) : u(x), cost(y) {}
	bool operator<(const node &other) const { return cost > other.cost; }
};

void dijkstra() {
	for (int i = 1; i <= n + 1; ++i)
		cost_dijkstra[i] = 1e19L;
	priority_queue<node> q;
	q.emplace(0, 0.0L);
	while (!q.empty()) {
		int u = q.top().u;
		ld cost = q.top().cost;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		for (int i = 0; i <= n + 1; ++i) {
			if (i == u || vis[i])
				continue;
			if (edges[i][u] + cost < cost_dijkstra[i]) {
				cost_dijkstra[i] = edges[i][u] + cost;
				q.emplace(i, cost_dijkstra[i]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	c[0].read();
	c[N - 1].read();
	cin >> n;
	c[n + 1] = c[N - 1];
	for (int i = 1; i <= n; ++i) {
		c[i].read();
		cin >> r[i];
	}
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = i + 1; j <= n + 1; ++j) {
			ld dis = sqrtl(ld(c[i].x - c[j].x) * (c[i].x - c[j].x) + ld(c[i].y - c[j].y) * (c[i].y - c[j].y));
			edges[i][j] = edges[j][i] = max(0.0L, dis - r[i] - r[j]);
		}
	}

	dijkstra();

	cout << cost_dijkstra[n + 1] << '\n';

	return 0;
}
