#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);

#define REP(i,n)	for(int i=0;i<(int)n;++i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define FOR(i,s,n)	for(int i=s;i<(int)n;++i)

ll xs, ys, xt, yt, n;
ll x[1000], y[1000], r[1000];

struct Edge { int to; long double cost; };
vector<Edge> es[1002];

long double dist(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2) {
	ll dx = x1 - x2, dy = y1 - y2, sr = r1 + r2;
	if (dx * dx + dy * dy <= sr * sr) return 0.0;
	else return sqrt(dx * dx + dy * dy) - sr;
}

long double d[1002];

typedef pair<long double, int> P;

int main(int argc, char **argv) {
	cin >> xs >> ys >> xt >> yt >> n;
	REP(i, n) cin >> x[i] >> y[i] >> r[i];
	REP(i, n) {
		long double d1 = dist(xs, ys, 0, x[i], y[i], r[i]);
		es[0].push_back({ 2 + i, d1 });
		es[2 + i].push_back({ 0, d1 });
		long double d2 = dist(xt, yt, 0, x[i], y[i], r[i]);
		es[1].push_back({ 2 + i, d2 });
		es[2 + i].push_back({ 1, d2 });
	}
	REP(i, n) REP(j, n) {
		long double d = dist(x[i], y[i], r[i], x[j], y[j], r[j]);
		es[2 + i].push_back({ 2 + j, d });
		es[2 + j].push_back({ 2 + i, d });
	}
	long double d12 = dist(xs, ys, 0, xt, yt, 0);
	es[0].push_back({ 1, d12 });
	es[1].push_back({ 0, d12 });
	REP(i, n + 2) d[i] = 3.0 * 1000000000;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push(MP(0.0, 0));
	d[0] = 0.0;
	while (!q.empty()) {
		P t = q.top(); q.pop();
		long double c = t.first;
		int v = t.second;
		if (c > d[v]) continue;
		d[v] = c;
		REP(i, es[v].size()) {
			Edge e = es[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				q.push(MP(d[v] + e.cost, e.to));
			}
		}
	}
	cout << fixed << setprecision(11) << d[1] << endl;
	return 0;
}
