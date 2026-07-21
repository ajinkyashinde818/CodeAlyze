#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct Point {
	double x, y;

	Point () {}
	Point (double _x, double _y) {
		x = _x; y = _y;
	}

	Point operator+ (const Point & other) const {
		return Point (x + other.x, y + other.y);
	}

	Point operator- (const Point & other) const {
		return Point (x - other.x, y - other.y);
	}

	double operator^ (const Point & other) const {
		return x * other.y - y * other.x;
	}

	double operator* (const Point & other) const {
		return x * other.x + y * other.y;
	}

	double operator~ () const {
		return sqrt (x * x + y * y);
	}
};

struct Circle {
	Point o;
	double r;

	Circle () {}
	Circle (Point _o, double _r) {
		o = _o; r = _r;
	}

	double getDist (Circle c) {
		double d = ~(o - c.o);
		double ans = d - r - c.r;
		if (ans < 0) return 0;
		return ans;
	}
};

const int MAXN = 1123;

Circle v[MAXN];
vector <pair <int, double> > g[MAXN];
double dist[MAXN];

int main () {

	Point s, t;
	scanf ("%lf %lf %lf %lf", &s.x, &s.y, &t.x, &t.y);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		scanf ("%lf %lf %lf", &v[i].o.x, &v[i].o.y, &v[i].r);

	v[n++] = Circle (s, 0);
	v[n++] = Circle (t, 0);

	for (int i = 0; i < n; ++i) {
		dist[i] = HUGE_VAL;
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			g[i].push_back (make_pair (j, v[i].getDist (v[j])));
		}
	}

	dist[n - 2] = 0;
	priority_queue <pair <double, int> > pq;

	pq.push (make_pair (0, n - 2));

	while (!pq.empty()) {
		int x = pq.top().second;
		double d = -pq.top().first;

		pq.pop();

		if (dist[x] < d) continue;

		for (int i = 0; i < g[x].size(); ++i) {
			int y = g[x][i].first;
			double nd = d + g[x][i].second;
			if (dist[y] - EPS > nd) {
				dist[y] = nd;
				pq.push (make_pair (-nd, y));
			}
		}
	}

	cout << fixed << setprecision (12) << dist[n - 1] << endl;

	return 0;
}
