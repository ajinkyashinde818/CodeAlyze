#include <bits/stdc++.h>

typedef long double db;
const int N = 1005;
db dis[N];

struct circle { int x, y, r; } p[N];
db distance(circle a, circle b) {
	int x = a.x - b.x, y = a.y - b.y;
	db dis = std::sqrt((db) x * x + (db) y * y);
	return std::max(dis - a.r - b.r, (db) 0);
}

bool vis[N];
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	int x, y, n; std::cin >> p[0].x >> p[0].y >> x >> y >> n;
	++n, p[n].x = x, p[n].y = y;
	for (int i = 1; i < n; ++i)
		std::cin >> p[i].x >> p[i].y >> p[i].r;
	for (int i = 1; i <= n; ++i) dis[i] = 1e10;
	for (int t = 0; t <= n; ++t) {
		int min = -1;
		for (int i = 0; i <= n; ++i)
			if (!vis[i] && (min == -1 || dis[i] < dis[min])) min = i;
		vis[min] = 1;
		for (int i = 0; i <= n; ++i)
			if (!vis[i]) dis[i] = std::min(dis[i], dis[min] + distance(p[min], p[i]));
	}
	std::cout << std::fixed << std::setprecision(18) << dis[n] << '\n';
	return 0;
}
