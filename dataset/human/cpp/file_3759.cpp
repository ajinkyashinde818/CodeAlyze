#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#define MOD 1000000007
#define MOD2 998244353
#define int long long
//#define PI 3.14159265358979

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

template < typename T >
ostream &operator<<(ostream &os, const vector< T > &A) {
	for (int i = 0; i < A.size(); i++)
		os << A[i] << " ";
	os << endl;
	return os;
}
template <>
ostream &operator<<(ostream &os, const vector< vector< int > > &A) {
	int N = A.size();
	int M;
	if (N > 0)
		M = A[0].size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			os << A[i][j] << " ";
		os << endl;
	}
	return os;
}

typedef pair< int, int > pii;
typedef long long ll;

struct edge {
	int from, to, c;
	double d;
	edge(int _from = 0, int _to = 0, double _d = 0, int _c = 0) {
		from = _from;
		to = _to;
		d = _d;
		c = _c;
	}
	bool operator<(const edge &rhs) const {
		return (d == rhs.d) ? (c < rhs.c) : (d < rhs.d);
	}
};

typedef vector< edge > edges;
typedef vector< edges > graph;
struct flow {
	int to, cap, rev, cost;
	flow(int to = 0, int cap = 0, int rev = 0, int cost = 0) : to(to), cap(cap), rev(rev), cost(cost) {}
};
typedef vector< vector< flow > > flows;

const int di[4] = {0, -1, 0, 1};
const int dj[4] = {-1, 0, 1, 0};
const int ci[5] = {0, 0, -1, 0, 1};
const int cj[5] = {0, -1, 0, 1, 0};
const ll LINF = LLONG_MAX / 2;
const int INF = INT_MAX / 2;
const double PI = acos(-1);

template < typename T, typename U >
bool chmin(T &x, const U &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}
template < typename T, typename U >
bool chmax(T &x, const U &y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

struct initializer {
	initializer() {
		cout << fixed << setprecision(13);
	}
};
initializer _____;
struct point {
	double x, y;
	point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	point operator+(const point &rhs) const {
		return point(x + rhs.x, y + rhs.y);
	}
	point operator-(const point &rhs) const {
		return point(x - rhs.x, y - rhs.y);
	}
	point operator*(const double d) const {
		return point(x * d, y * d);
	}
};
double dot(const point &a, const point &b) {
	return a.x * b.x + a.y * b.y;
}
double det(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}
struct circle {
	double r, x, y;
	circle(double r = 0.0, double x = 0.0, double y = 0.0) : r(r), x(x), y(y) {}
	circle(double r, point p) : r(r), x(p.x), y(p.y) {}
	point getCenter() { return point(x, y); }
};
double dist(point a, point b) {
	double x = a.x - b.x;
	double y = a.y - b.y;
	return sqrt(x * x + y * y);
}
bool getCircle(point p1, point p2, double r, point &pc1, point &pc2) {
	bool stat = true;
	point p3;
	double d, l, dx, dy;
	p3.x = (p1.x + p2.x) * 0.5;
	p3.y = (p1.y + p2.y) * 0.5;
	r *= r;
	l = (p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y);
	if (r >= l) {
		d = sqrt(r / l - 1.0);
		dx = d * (p2.y - p3.y);
		dy = d * (p2.x - p3.x);

		pc1.x = p3.x + dx;
		pc1.y = p3.y - dy;

		pc2.x = p3.x - dx;
		pc2.y = p3.y + dy;
	} else {
		stat = false;
	}

	return stat;
}
vector< double > dijkstra(graph &G, int s) {
	///stat must have "<"&">"
	///init d=vector<stat>
	vector< double > d(G.size(), (double)LINF);
	d[s] = 0;
	//init q=p-queue<pair<stat,index> >
	priority_queue< pair< double, int >, vector< pair< double, int > >, greater< pair< double, int > > > q;
	q.push(pair< double, int >(0.0, s));

	while (!q.empty()) {
		pair< double, int > p = q.top();
		q.pop();
		if (d[p.second] < p.first)
			continue;
		for (int i = 0; i < G[p.second].size(); i++) {
			edge e = G[p.second][i];
			if (p.first + e.d < d[e.to]) {
				d[e.to] = p.first + e.d;
				q.push(pair< double, int >(d[e.to], e.to));
			}
		}
	}
	return d;
}
int N, M, K, T, Q;
signed main() {
	point s, t;
	cin >> s.x >> s.y >> t.x >> t.y;
	cin >> N;
	vector< circle > cs(N);
	rep(i, N) {
		cin >> cs[i].x >> cs[i].y >> cs[i].r;
	}
	vector< vector< edge > > G(N + 2);
	rep(i, N) rep(j, N) if (i != j) {
		double d = dist(cs[i].getCenter(), cs[j].getCenter()) - cs[i].r - cs[j].r;
		if (d < 0.0)
			d = 0.0;
		G[i].push_back(edge(i, j, d));
	}
	rep(i, N) {
		circle c = cs[i];
		double d = dist(c.getCenter(), s) - c.r;
		if (d < 0.0)
			d = 0.0;
		G[N].emplace_back(N, i, d);
	}
	rep(i, N) {
		circle c = cs[i];
		double d = dist(c.getCenter(), t) - c.r;
		if (d < 0.0)
			d = 0.0;
		G[i].emplace_back(i, N + 1, d);
	}
	G[N].emplace_back(N, N + 1, dist(s, t));
	vector< double > d = dijkstra(G, N);
	cout << d[N + 1] << endl;
	return 0;
}
