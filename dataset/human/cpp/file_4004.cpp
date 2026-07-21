#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Edge {
    int to; T cost;
    Edge (int to, T cost = 1) : to(to), cost(cost) { }
    bool operator< (const Edge &r) const { return (cost < r.cost); }
};

template<typename T>
using Graph = vector<vector<Edge<T>>>;

template <typename T>
vector<T> dijkstra(const Graph<T> &g, int s){
    using P = pair<T, int>;
    vector<T> ret(g.size(), -1);
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(ret[s], s); ret[s] = 0;
    while (not que.empty()) {
        int v; T c; tie(c, v) = que.top(); que.pop();
        if (ret[v] < c) continue;
        for (const auto &e : g[v]) {
            if (ret[e.to] > ret[v] + e.cost or ret[e.to] == -1) {
                ret[e.to] = ret[v] + e.cost;
                que.emplace(ret[e.to], e.to);
            }
        }
    }
    return ret;
}

long double f (long double x) { return (x * x); }

int main() {
    long double a, b, c, d;
    int n;
    cin >> a >> b >> c >> d >> n;
    vector<pair<long double, long double>> p(n);
    vector<long double> r(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second >> r[i];
    }
    
    p.emplace_back(a, b); r.emplace_back(0);
    p.emplace_back(c, d); r.emplace_back(0);
    
    Graph<long double> g(n + 2);
    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            long double d = f(p[i].first - p[j].first) + f(p[i].second - p[j].second);
            d = sqrtl(d);
            d = max(0.0L, (long double)d - (r[i] + r[j]));
            g[i].emplace_back(j, d);
            g[j].emplace_back(i, d);
        }
    }
    
    vector<long double> dat = dijkstra(g, n);
    
    cout << fixed << setprecision(20) << dat[n + 1] << '\n';
    
    return 0;
}
