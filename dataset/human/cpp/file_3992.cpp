#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
typedef pair<double, int> P;
vector<P> G[1010];
double x[1010];
double y[1010];
double r[1010];
double dist[1010];
int main() {
	int xs, ys, xt, yt;
	cin >> xs >> ys >> xt >> yt;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x[i] >> y[i] >> r[i];
	}
	x[0] = xs;
	y[0] = ys;
	r[0] = 0;
	x[N + 1] = xt;
	y[N + 1] = yt;
	r[N + 1] = 0;
	for (int i = 0; i <= N + 1; i++) {
		for (int j = i + 1; j <= N + 1; j++) {
			double d = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
			double cost = max(d - (r[i] + r[j]), 0.0);
			G[i].emplace_back(cost, j);
			G[j].emplace_back(cost, i);
		}
	}
	priority_queue<P, vector<P>, greater<P>> Q;
	fill(dist, dist + 1010, 1e100);
	dist[0] = 0;
	Q.push(P(0, 0));
	while (!Q.empty()) {
		P p = Q.top(); Q.pop();
		if (dist[p.second] < p.first) continue;
		for (P e : G[p.second]) {
			int to = e.second;
			if (p.first + e.first < dist[to]) {
				dist[to] = p.first + e.first;
				Q.push(P(dist[to], to));
			}
		}
	}
	printf("%.15lf\n", dist[N + 1]);
}
