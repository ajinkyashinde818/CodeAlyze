#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef vector<double> vd;

struct circle {	int x; int y; int r; };
const double INF = 1e15;

int N;
vector<circle> C;
vector<vd> cost;
vd d;
vector<bool> used;

void dijkstra(int s) {
	d.resize(N + 2, INF);
	used.resize(N + 2, false);
	d[s] = 0.0;

	while (true) {
		int v = -1;
		for (int u = 0; u < N + 2; u++) {
			if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		if (v == -1) break;
		used[v] = true;
		for (int u = 0; u < N + 2; u++) {
			d[u] = min(d[u], d[v] + cost[v][u]);
		}
	}
}

int main(void) {
	int x_s, y_s, x_t, y_t;

	cin >> x_s >> y_s >> x_t >> y_t;
	cin >> N;

	C.resize(N + 2);
	C[0].x = x_s;	C[0].y = y_s;	C[0].r = 0;
	C[N + 1].x = x_t;	C[N + 1].y = y_t;	C[N + 1].r = 0;
	for (int i = 1; i <= N; ++i)
		cin >> C[i].x >> C[i].y >> C[i].r;
	
	vd vinf;
	vinf.resize(N + 2, INF);
	cost.resize(N + 2, vinf);
	for (int i = 0; i <= N; ++i) {
		for (int j = i + 1; j <= N + 1; ++j) {
			double xx = (double)(C[i].x - C[j].x) * (double)(C[i].x - C[j].x);
			double yy = (double)(C[i].y - C[j].y) * (double)(C[i].y - C[j].y);
			double dst = sqrt(xx + yy) - (C[i].r + C[j].r);
			if (dst < 0)
				dst = 0.0;
			cost[i][j] = cost[j][i] = dst;
		}
	}

	dijkstra(0);

	cout << fixed << setprecision(15) << d[N + 1] << '\n';
	return 0;
}
