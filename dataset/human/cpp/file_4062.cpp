#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

typedef pair<long long int, long long int> P;

double cost[1010][1010];
double d[1010];
bool used[1010];
int V;

#define INF 2000000010000.0

void dijkstra(int s) {
	fill(d, d+V, INF);
	fill(used, used+V, false);
	d[s] = 0.0;

	while (true) {
		int v = -1;
		for (int u = 0; u < V; u++) {
			if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		if (v == -1) break;
		used[v] = true;
		for (int u = 0; u < V; u++) {
			d[u] = min(d[u], d[v]+cost[v][u]);
		}
	}
}

double dist(P a, P b, long long int ra, long long int rb) {
	double dd = sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
	if ((double)ra+(double)rb > dd) {
		dd = 0;
	} else {
		dd -= (ra+rb);
	}
	return dd;
}

int main() {
	long long int sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy;
	int n;
	cin >> n;
	vector<P> xy(n+2);
	vector<long long int> rr(n+2);
	xy[0] = P(sx, sy);
	rr[0] = 0;
	xy[1] = P(gx, gy);
	rr[1] = 0;
	long long int x, y, r;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> r;
		xy[i+2] = P(x, y);
		rr[i+2] = r;
	}
	V = n+2;
	for (int i = 0; i < n+2; i++) {
		for (int j = 0; j < n+2; j++) {
			cost[i][j] = dist(xy[i], xy[j], rr[i], rr[j]);
		}
	}
	dijkstra(0);
	printf("%.15f\n", d[1]);
	return 0;
}
