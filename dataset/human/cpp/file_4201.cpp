#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;
const long long INFll = (1ull<<62) - 1;

struct Edge
{
	int to;
	double cost;
};

struct Dijkstra
{
	using P = pair<double, int>;
	int V;
	int s;
	const vector<vector<Edge>> &g;
	vector<double> dist;
	vector<int> previous;

	Dijkstra(const vector<vector<Edge>> &g) : V(g.size()), g(g) {}

	void calc(int start) {
		s = start;
		dist.assign(V, INFll);
		previous.assign(V, -1);
		dist[s] = 0;
		priority_queue<P, vector<P>, greater<P>> pque;
		pque.push(P(0, s));
		while (!pque.empty()) {
			P p = pque.top(); pque.pop();
			int v = p.second;
			if (p.first > dist[v]) continue;
			for (Edge e : g[v]) {
				if (dist[e.to] > dist[v] + e.cost) {
					dist[e.to] = dist[v] + e.cost;
					previous[e.to] = v;
					pque.push(P(dist[e.to], e.to));
				}
			}
		}
	}
};

struct T
{
	long long x, y, r;
};

double dist(T &a, T &b) {
	const double dx = a.x - b.x, dy = a.y - b.y;
	return max((double)0, sqrt(dx*dx + dy*dy) - a.r - b.r);
}

int main() {
	T s, t;
	cin >> s.x >> s.y >> t.x >> t.y;
	s.r = t.r = 0;
	int n;
	cin >> n;
	vector<T> v(n+2);
	v[0] = s, v[1] = t;
	for (int i = 0; i < n; i++) {
		cin >> v[i+2].x >> v[i+2].y >> v[i+2].r;
	}
	vector<vector<Edge>> g(n+2);
	for (int i = 0; i < n+2; i++) {
		for (int j = i+1; j < n+2; j++) {
			double d = dist(v[i], v[j]);
			g[i].push_back({j, d});
			g[j].push_back({i, d});
		}
	}
	Dijkstra D(g);
	D.calc(0);
	double ans = D.dist[1];
	cout << fixed << setprecision(20) << ans << endl;
	return 0;
}
