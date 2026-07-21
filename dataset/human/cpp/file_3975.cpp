#include <bits/stdc++.h>

using namespace std;

const long double INF = 1E15;
const int MAXN = 1000;
long double adjMat[MAXN + 3][MAXN + 3];
long double dist[MAXN + 3];
bool visited[MAXN + 3];
tuple<int, int, int> circles[MAXN + 3];

int main()
{
    int xs, ys, xt, yt, n;
    cin >> xs >> ys >> xt >> yt >> n;
    circles[n + 1] = make_tuple(xs, ys, 0);
    circles[n + 2] = make_tuple(xt, yt, 0);
    for (int i = 1; i <= n; i++)
    {
        int x, y, r;
        cin >> x >> y >> r;
        circles[i] = make_tuple(x, y, r);
    }
    for (int i = 1; i <= n + 2; i++)
    {
        for (int j = i + 1; j <= n + 2; j++)
        {
            int dx = abs(get<0>(circles[i]) - get<0>(circles[j]));
            int dy = abs(get<1>(circles[i]) - get<1>(circles[j]));
            long double d = sqrt((long long) dx * dx + (long long) dy * dy) - (get<2>(circles[i]) + get<2>(circles[j]));
            d = max(d, (long double) 0);
            adjMat[i][j] = adjMat[j][i] = d;
        }
    }
    fill(dist + 1, dist + n + 3, INF);
    dist[n + 1] = 0;
    for (int i = 0; i < n + 2; i++)
    {
        long double minDist = INF;
        int u = 1;
        for (int j = 1; j <= n + 2; j++)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }
        for (int j = 1; j <= n + 2; j++)
        {
            dist[j] = min(dist[j], dist[u] + adjMat[u][j]);
        }
        visited[u] = true;
    }
    cout << fixed << setprecision(10) << dist[n + 2] << endl;
    return 0;
}
