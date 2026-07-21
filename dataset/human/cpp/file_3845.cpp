#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <deque>
#include <cctype>
#include <stack>
#include <bitset>
#include <set>

using ll = long long;
using namespace std;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

const ll MOD = 1000000007;
const ll INF = 1 << 30;
const ll INF2 = 9000000000000000000LL;
const double INF3 = 900000000000000;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
#define ALL(x) (x).begin(),(x).end()

struct edge { int to; double cost;};
vector<edge>v[10100];
double d[10100];

int main() {
	ll sx, sy, gx, gy, x[10100], y[10100], r[10100];
	int n;
	double ans;
	cin >> sx >> sy >> gx >> gy >> n;
	for (int i = 1;i <= n;i++) {
		cin >> x[i] >> y[i] >> r[i];
	}
	x[0] = sx, y[0] = sy, r[0] = 0, x[n + 1] = gx, y[n + 1] = gy, r[n + 1] = 0;
	for (int i = 0;i <= n + 1;i++) {
		for (int j = 0;j <= n + 1;j++) {
			if (i == j)continue;
			double c = max((long double)0, sqrtl((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) - (r[i] + r[j]));
			v[i].push_back(edge{ j,c });
			v[j].push_back(edge{ i,c });
		}
	}
	for (int i = 0;i <= n+1;i++) {
		d[i] = INF3;
	}
	d[0] = 0.0;
	std::priority_queue<P, std::vector<P>, std::greater<P>>pq;
	pq.push(make_pair(d[0], 0));
	while (!pq.empty()) {
		P a = pq.top();
		pq.pop();
		int i = a.second;
		if (d[i] < a.first)continue;
		for (int k = 0;k < v[i].size();k++) {
			edge e = v[i][k];
			if (d[e.to] <= d[i] + e.cost)continue;
			d[e.to] = d[i] + e.cost;
			pq.push(make_pair(d[e.to], e.to));
		}
	}
	std::cout << setprecision(24) <<  d[n + 1] << std::endl;

}
