#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const int bits = 20;
struct edge {
	int to, cost;
};
struct state {
	int pos, cost, dist, pop, par;
};
bool operator<(const state& s1, const state& s2) {
	if (s1.cost != s2.cost) return s1.cost > s2.cost;
	if (s1.dist != s2.dist) return s1.dist > s2.dist;
	return s1.pop > s2.pop;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> t(N);
	for (int i = 0; i < N; ++i) cin >> t[i];
	vector<vector<edge> > G(N);
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c; --a, --b;
		G[a].push_back(edge{ b, c });
		G[b].push_back(edge{ a, c });
	}
	priority_queue<state> que;
	que.push(state{ 0, 0, 0, t[0], -1 });
	vector<int> p(N, -2), pc(N), days(N), costs(N);
	while (!que.empty()) {
		state u = que.top(); que.pop();
		if (p[u.pos] == -2) {
			p[u.pos] = u.par;
			days[u.pos] = u.dist;
			costs[u.pos] = u.cost;
			for (edge e : G[u.pos]) {
				if (p[e.to] == -2) {
					que.push(state{ e.to, u.cost + e.cost, u.dist + 1, t[u.pos], u.pos });
				}
			}
		}
	}
	vector<vector<int> > xp(bits, vector<int>(N));
	xp[0] = p; xp[0][0] = 0;
	for (int i = 1; i < bits; ++i) {
		for (int j = 0; j < N; ++j) {
			xp[i][j] = xp[i - 1][xp[i - 1][j]];
		}
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int pos, day, money;
		cin >> pos >> day >> money; --pos;
		int forward = max(days[pos] - day, 0);
		int fpos = pos;
		for (int j = bits - 1; j >= 0; --j) {
			if ((forward >> j) & 1) fpos = xp[j][fpos];
		}
		int least = costs[pos] - costs[fpos];
		int ans = least + max(costs[fpos] - money, 0);
		cout << ans << '\n';
	}
	return 0;
}
