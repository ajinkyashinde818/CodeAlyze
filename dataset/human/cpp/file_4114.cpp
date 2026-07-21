#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

template <typename T>
vector<T> dijkstra(int s, vector<vector<pair<int, T>>> &G) {
    const T inf = numeric_limits<T>::max();
    using P     = pair<T, int>;
    int n       = G.size();
    vector<T> d(n, inf);
    priority_queue<P, vector<P>, greater<P>> q;
    d[s] = 0;
    q.emplace(d[s], s);
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        for (auto &e : G[v]) {
            int u = e.first;
            T c   = e.second;
            if (d[u] > d[v] + c) {
                d[u] = d[v] + c;
                q.emplace(d[u], u);
            }
        }
    }
    return d;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<lint> x(2), y(2);
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    lint n;
    cin >> n;
    x.resize(n + 2);
    y.resize(n + 2);
    vector<lint> r(n + 2, 0);
    for (int i = 0; i < n; ++i) {
        cin >> x[i + 2] >> y[i + 2] >> r[i + 2];
    }
    vector<vector<pair<int, double>>> edges(n + 2);
    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < n + 2; ++j) {
            double dist = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            dist        = max(0.0, dist - r[i] - r[j]);
            edges[i].emplace_back(j, dist);
        }
    }
    auto d = dijkstra(0, edges);
    cout << fixed << setprecision(10) << d[1] << "\n";
    return 0;
}
