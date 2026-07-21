#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
static const int MAXN = 1004;
static const double INF = 1e21;

int xs, ys, xt, yt;
int n, x[MAXN], y[MAXN], r[MAXN];

double d[MAXN][MAXN];

template <typename T> inline T sqr(const int x) { return (T)x * x; }

double dijkstra(int src, int dst)
{
    typedef std::pair<double, int> vert_info;
    std::priority_queue<vert_info, std::vector<vert_info>, std::greater<vert_info>> q;

    double dist[MAXN];
    for (int i = 0; i < n; ++i) dist[i] = INF;
    dist[src] = 0; q.push({ 0, src });

    while (!q.empty()) {
        vert_info u;
        do { u = q.top(); q.pop(); } while (dist[u.second] != u.first && !q.empty());
        if (dist[u.second] != u.first) break;
        for (int v = 0; v < n; ++v)
            if (dist[v] > u.first + d[u.second][v]) {
                dist[v] = u.first + d[u.second][v];
                q.push({ dist[v], v });
            }
    }
    return dist[dst];
}

int main()
{
    scanf("%d%d%d%d", &xs, &ys, &xt, &yt);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d%d", &x[i], &y[i], &r[i]);
    n += 2;
    x[n - 2] = xs, y[n - 2] = ys;
    x[n - 1] = xt, y[n - 1] = yt;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            d[i][j] = std::max(0., sqrt(sqr<double>(x[i] - x[j]) + sqr<double>(y[i] - y[j])) - (r[i] + r[j]));

    printf("%.12lf\n", dijkstra(n - 2, n - 1));
    return 0;
}
