#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

struct Point {
	double x, y;
	void read() {
		scanf("%lf%lf", &x, &y);
	}
};

struct Cir {
	Point o;
	double r;
	void read() {
		o.read();
		scanf("%lf", &r);
	}
} c[N];

int n;
Cir s, t;

double g[N][N];

double dist(Point a, Point b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

double get(Cir a, Cir b) {
	double d = dist(a.o, b.o);
	return max(0.0, d - (a.r + b.r));
}

queue<int> Q;
int vis[N];
double d[N];

int main() {
	s.o.read(); t.o.read();
	scanf("%d", &n); n += 2;
	c[1] = s; c[2] = t;
	for (int i = 3; i <= n; i++) c[i].read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = get(c[i], c[j]);
	for (int i = 1; i <= n; i++) d[i] = 1e20;
	vis[1] = 1;
	d[1] = 0;
	Q.push(1);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		vis[u] = 0;
		for (int v = 1; v <= n; v++) {
			if (d[v] > d[u] + g[u][v]) {
				d[v] = d[u] + g[u][v];
				if (!vis[v]) {
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
	}
	printf("%.12f\n", d[2]);
	return 0;
}
