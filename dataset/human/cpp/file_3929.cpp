#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <climits>

#include <sstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false)

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int max_N = 1e3 + 10;
const ld inf = 1e18;

ll X[max_N], Y[max_N], R[max_N];
int popped[max_N];
vector< pair<int, ld> > E[max_N];
ld dist[max_N];
int N;

template<typename T>
T sqr(const T &x) {return x * x;}
ld distance(int i, int j);
ld dijkstra();

int main()
{
	int xt, yt;
	cin >> X[0] >> Y[0] >> xt >> yt;
	cin >> N;
	X[N + 1] = xt;
	Y[N + 1] = yt;
	for (int i = 1; i <= N; ++i) {
		cin >> X[i] >> Y[i] >> R[i];
	}
	for (int i = 0; i <= N + 1; ++i) {
		for (int j = i + 1; j <= N + 1; ++j) {
			ld temp = max(distance(i, j) - R[i] - R[j], ld(0));
			E[i].push_back({j, temp});
			E[j].push_back({i, temp});
		}
	}
	cout << fixed << setprecision(12) << dijkstra() << endl;
}

ld distance(int i, int j)
{
	return sqrt(sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]));
}

ld dijkstra()
{
	for (int i = 1; i <= N + 1; ++i) {
		dist[i] = inf;
	}
	priority_queue< pair<ld, int>, vector< pair<ld, int> >, greater< pair<ld, int> > > dfq;
	dfq.push({0, 0});
	while(!dfq.empty() && !popped[N + 1]) {
		auto u = dfq.top();
		dfq.pop();
		if (!popped[u.second]) {
			popped[u.second] = 1;
			for (auto &v : E[u.second]) {
				if (dist[v.first] > dist[u.second] + v.second) {
					dist[v.first] = dist[u.second] + v.second;
					dfq.push({dist[v.first], v.first});
				}
			}
		}
	}
	return dist[N + 1];
}
