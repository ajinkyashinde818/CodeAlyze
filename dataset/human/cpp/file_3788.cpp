#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
using namespace std;

typedef long long ll;

double d[1005][1005];
ll x[1003], y[1003], r[1003];
bool used[1005];

int main() {
	ll xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
	int n; cin >> n;
	x[0] = xs; y[0] = ys; r[0] = 0;
	x[n + 1] = xt; y[n + 1] = yt; r[n + 1] = 0;
	for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i] >> r[i];
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= n + 1; ++j) {
			if (i == j) continue;
			d[i][j] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) - r[i] - r[j];
			if (d[i][j] < 0) d[i][j] = 0;
		}
	}

	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> que;
	for (int i = 1; i <= n + 1; ++i) {
		que.push({ d[0][i], i });
	}
	used[0] = true;
	while (!que.empty()) {
		double dis = que.top().first;
		int pos = que.top().second;
		que.pop();
		if (used[pos]) continue;
		used[pos] = true;
		d[pos][0] = d[0][pos] = dis;
		for (int i = 1; i <= n + 1; ++i) {
			if (used[i]) continue;
			que.push({ d[0][pos] + d[pos][i], i });
		}
	}
	printf("%.10f\n", d[0][n + 1]);
	return 0;
}
