/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define sqr(x) (x) * (x)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 10;
const ld inf = 1e18;

struct circle {
	ld x, y, r = 0;
	ld dist(circle &c) {
		ld ans = sqr(x - c.x) + sqr(y - c.y);
		ans = sqrt(ans) - r - c.r;
		ans = max(ld(0), ans);
		return ans;
	}
} p[N];

ld g[N][N];

ld dijsktra(int s, int t, int n);

int main() {
	cin >> p[1].x >> p[1].y >> p[2].x >> p[2].y;
	int n; cin >> n;
	n += 2;
	for (int i = 3; i <= n; ++i) {
		cin >> p[i].x >> p[i].y >> p[i].r;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			g[i][j] = g[j][i] = p[i].dist(p[j]);
		}
	}
	cout << fixed << setprecision(20) << dijsktra(1, 2, n);
}

ld dijsktra(int s, int t, int n) {
	vector<ld> dist(n + 1);
	vector<bool> seen(n + 1);
	for (int i = 0; i <= n; ++i) {
		dist[i] = inf;
		seen[i] = 0;
	}
	dist[s] = 0;
	for (int i = 0; i < n; ++i) {
		int cur = 0;
		for (int j = 1; j <= n; ++j) {
			if (!seen[j] and dist[j] < dist[cur]) {
				cur = j;
			}
		}
		for (int j = 1; j <= n; ++j) {
			if (dist[cur] + g[cur][j] < dist[j]) {
				dist[j] = dist[cur] + g[cur][j];
			}
		}
		seen[cur] = true;
	}
	return dist[t];
}
