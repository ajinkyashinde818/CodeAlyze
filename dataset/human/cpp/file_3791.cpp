#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

struct barrier {
    double x, y, r;
    barrier(double _x, double _y, double _r) : x(_x), y(_y), r(_r) {}
};

struct edge {
    int to;
    double cost;
    edge(int t, double c) : to(t), cost(c) {}
};

using pid = pair<int, double>;
void dijkstra(int s, vector<double> &d, vector<vector<edge>> &G) {
    priority_queue<pid, vector<pid>, greater<pid>> que;
    fill(All(d), (double)1e18);
    d[s] = 0;
    que.push(make_pair(0, s));

    while(!que.empty()) {
        pid p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first)
            continue;
        for(auto e : G[v]) {
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(make_pair(d[e.to], e.to));
            }
        }
    }
}

int main() {
    double sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int N;
    cin >> N;
    vector<barrier> bs(N, barrier(0, 0, 0));
    for(int i = 0; i < N; i++) {
        double x, y, r;
        cin >> x >> y >> r;
        bs[i] = barrier(x, y, r);
    }
    vector<vector<edge>> G(N + 2, vector<edge>());
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            double d = sqrt((bs[i].x - bs[j].x) * (bs[i].x - bs[j].x) +
                            (bs[i].y - bs[j].y) * (bs[i].y - bs[j].y));
            d -= bs[i].r + bs[j].r;
            d = max((double)0.0, d);
            G[i].pb(edge(j, d));
            G[j].pb(edge(i, d));
        }
    }
    for(int j = 0; j < N; j++) {
        double d = sqrt((sx - bs[j].x) * (sx - bs[j].x) +
                        (sy - bs[j].y) * (sy - bs[j].y));
        double d2 = sqrt((tx - bs[j].x) * (tx - bs[j].x) +
                         (ty - bs[j].y) * (ty - bs[j].y));
        d -= bs[j].r;
        d2 -= bs[j].r;
        d = max((double)0.0, d);
        d2 = max((double)0.0, d2);
        G[N].pb(edge(j, d));
        G[j].pb(edge(N + 1, d2));
    }
    G[N].pb(edge(N + 1, sqrt((sx - tx) * (sx - tx) + (sy - ty) * (sy - ty))));

    vector<double> dist(N + 2);
    dijkstra(N, dist, G);
    cout << fixed << setprecision(10) << dist[N + 1] << endl;
    return 0;
}
