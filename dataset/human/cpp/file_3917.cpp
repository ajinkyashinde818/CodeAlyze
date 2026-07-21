#include <cstdio>
#include <algorithm>
#include <cmath>
int N, v[1002];
long double x[1002], y[1002], r[1002], g[1002][1002], dis[1002];
int main()
{
	scanf("%Lf%Lf%Lf%Lf%d", x, y, x + 1, y + 1, &N);
	N += 2;
	std::swap(x[1], x[N - 1]);
	std::swap(y[1], y[N - 1]);
	for (int i = 1; i < N - 1; i++)
		scanf("%Lf%Lf%Lf", x + i, y + i, r + i);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			g[i][j] = std::max(0.0L, std::sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - r[i] - r[j]);
	for (int i = 1; i < N; i++)
		dis[i] = 1e100;
	do
	{
		int u = -1;
		for (int i = 0; i < N; i++)
			if (!v[i] && (!~u || dis[i] < dis[u]))
				u = i;
		if (!~u)
			break;
		v[u] = 1;
		for (int i = 0; i < N; i++)
			dis[i] = std::min(dis[i], dis[u] + g[u][i]);
	}
	while (1);
	printf("%.10Lf\n", dis[N - 1]);
	return 0;
}
