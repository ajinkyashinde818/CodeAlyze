#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, int> P;

struct edge {
	int to;
	double cost;
};

double x[1010];
double y[1010];
double r[1010];
double d[1010];

vector<edge> G[1010];

double dist(int i, int j) {
	double dx = x[i] - x[j];
	double dy = y[i] - y[j];
	double d = sqrt(dx * dx + dy * dy);
	if(d < r[i] + r[j]) return 0;
	return d - (r[i] + r[j]);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	double xs, ys, xt, yt;
	int N;
	cin >> xs >> ys >> xt >> yt >> N;

	for(int i = 0; i < N; i++) {
		cin >> x[i] >> y[i] >> r[i];
	}
	x[N] = xs, y[N] = ys, r[N] = 0;
	x[N + 1] = xt, y[N + 1] = yt, r[N + 1] = 0;

	for(int i = 0; i < N + 2; i++) {
		for(int j = 0; j < N + 2; j++) {
			if(i == j) continue;
			G[i].push_back(edge{ j, dist(i, j) });
		}
	}

	fill(d, d + N + 2, 1e20);
	d[N] = 0;
	priority_queue <P, vector<P>, greater<P>> q;
	q.push(P(0, N));
	while(q.size()) {
		int v = q.top().second;
		double c = q.top().first;
		q.pop();
		if(d[v] < c) continue;
		for(auto e : G[v]) {
			if(d[e.to] >  c + e.cost) {
				d[e.to] = c + e.cost;
				q.push(P(d[e.to], e.to));
			}
		}
	}
	cout << fixed << setprecision(15) << d[N + 1] << endl;
}
