#include <algorithm>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps DBL_EPSILON
#define mod (ll)998244353
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int sx, sy, tx, ty, n, x[1010], y[1010], r[1010];
vector<pair<int, double>> vec[1010];
prique<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> que;
double dist[1010];
signed main() {
	cin >> sx >> sy >> tx >> ty >> n;
	x[0] = sx; y[0] = sy;
	x[n + 1] = tx; y[n + 1] = ty;
	REP(i, n) {
		cin >> x[i] >> y[i] >> r[i];
	}
	rep(i, n + 2) {
		rep(j, n + 2) {
			if (i == j)continue;
			vec[i].push_back(make_pair(j, max((double)0, hypot(x[i] - x[j], y[i] - y[j]) - r[i] - r[j])));
		}
	}
	REP(i, n + 1)dist[i] = DBL_MAX;
	que.push(make_pair(0, 0));
	while (!que.empty()) {
		auto node = que.top();
		que.pop();
		if (node.first > dist[node.second])continue;
		for (auto p : vec[node.second]) {
			if (dist[node.second] + p.second < dist[p.first]) {
				dist[p.first] = dist[node.second] + p.second;
				que.push(make_pair(dist[p.first], p.first));
			}
		}
	}
	printf("%.12lf\n", dist[n + 1]);
	return 0;
}
