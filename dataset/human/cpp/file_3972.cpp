#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
const double eps = 1e-12;
const double inf = 1e10;
typedef pair<double, int> di;

int n;
int x[N], y[N], r[N];
double d[N];
double f[N][N];

double dist(int i, int j) { return hypot(x[i] - x[j], y[i] - y[j]); }

void dijkstra() {
	for (int i = 1; i <= n; ++i) d[i] = inf;
	priority_queue < di, vector<di>, greater<di> > pq;
	pq.push(di(0, 0));
	while(!pq.empty()) {
		di t = pq.top(); pq.pop();
		int u = t.second; double du = t.first;
		if (!(abs(d[u] - du) <= eps)) continue;

		for (int v = 1; v <= n; ++v) if (u != v && d[v] > d[u] + f[u][v] + eps) {
			d[v] = d[u] + f[u][v];
			pq.push(di(d[v], v));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	cin >> n; ++n;
	for (int i = 2; i <= n; ++i) {
		cin >> x[i] >> y[i] >> r[i];
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			f[i][j] = dist(i, j) - r[i] - r[j];
			if (f[i][j] < -eps) f[i][j] = 0.0;
			f[j][i] = f[i][j];
		}
	}

	dijkstra();

	cout << setprecision(12) << fixed << d[1] << endl;
}
