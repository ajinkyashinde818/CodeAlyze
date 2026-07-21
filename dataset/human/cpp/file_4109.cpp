#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
using P = pair<double, double>;
using PP = pair<double, P>;

struct edge {
	P to;
	double cost;
};

void dijkstra(map<P, vector<edge>>& G, map<P, double>& d, P s) {
	priority_queue<PP, vector<PP>, greater<PP>> que;
	d[s] = 0;
	que.push(PP(0, s));

	while (!que.empty()) {
		PP q = que.top();
		que.pop();
		P v = q.second;
		if (d[v] < q.first) { continue; }

		for (int i = 0; i < G[v].size(); ++i) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(PP(d[e.to], e.to));
			}
		}
	}
}

int main() {
	const double INF = 1e18;
	double xs, ys, xt, yt;
	cin >> xs >> ys >> xt >> yt;
	int N;
	cin >> N;
	vector<double> x(N + 2);
	vector<double> y(N + 2);
	vector<double> r(N + 2);
	x[0] = xs; x[N + 1] = xt;
	y[0] = ys; y[N + 1] = yt;
	r[0] = 0.0; r[N + 1] = 0.0;
	for (int i = 1; i <= N; ++i) {
		cin >> x[i] >> y[i] >> r[i];
	}

	map<P, vector<edge>> G;
	for (int i = 0; i <= N + 1; ++i) {
		for (int j = 0; j <= N + 1; ++j) {
			if (j == i) { continue; }
			double dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
			double cost = max(0.0, dist - (r[i] + r[j]));
			G[P(x[i], y[i])].push_back({P(x[j], y[j]), cost});
		}
	}

	map<P, double> d;
	for (int i = 0; i <= N + 1; ++i) {
		d[P(x[i], y[i])] = INF;
	}

	dijkstra(G, d, P(xs, ys));
	double res = d[P(xt, yt)];
	cout.precision(15);
	cout << fixed << res << endl;

	return 0;
}
