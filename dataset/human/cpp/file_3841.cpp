#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using pii = pair<int, int>;

constexpr ld INF = 1e16;

struct edge {
    int to;
    ld cost;
};

using edges = vector<edge>;
using graph = vector<edges>;

int main() {
    ld xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int N;
    cin >> N;
    vector<ld> x(N + 2), y(N + 2), r(N + 2);
    x[N] = xs; y[N] = ys;
    x[N + 1] = xt; y[N + 1] = yt;
    for(int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i] >> r[i];
    }
    graph g(N + 2);
    for(int i = 0; i < N + 2; ++i) {
        for(int j = i + 1; j < N + 2; ++j) {
            ld dist = hypot(x[i] - x[j], y[i] - y[j]);
            dist = max((ld)0, dist - (r[i] + r[j]));
            g[i].push_back(edge{j, dist});
            g[j].push_back(edge{i, dist});
        }
    }
    vector<ld> d(N + 2, INF);
    d[N] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> que;
    que.push(make_pair(0, N));
    while(!que.empty()) {
        auto p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first) {
            continue;
        }
        for(auto& e : g[v]) {
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(make_pair(d[e.to], e.to));
            }
        }
    }
    cout << fixed << setprecision(10) << d[N + 1] << endl;
}
