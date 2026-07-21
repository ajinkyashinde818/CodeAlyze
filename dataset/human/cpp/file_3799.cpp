#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> struct Edge {
    int to;
    T cost;
    Edge(int t, T c) : to(t), cost(c) {}
};

template<typename T> vector<T> dijkstra(const vector<vector<Edge<T>>> g, int s) {
    T EPS = (T)1e-10;
    T INF = (T)1e18;
    vector<T> d(g.size(), INF);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> q;
    d.at(s) = 0;
    q.emplace(d.at(s), s);
    while ( !q.empty() ) {
        auto p = q.top();
        q.pop();
        int v = p.second;
        if ( d.at(v) + EPS < p.first ) continue;
        for ( auto e : g[v]) {
            if ( d.at(e.to) > d.at(v) + e.cost ) {
                d.at(e.to) = d.at(v) + e.cost;
                q.emplace(d.at(e.to), e.to);
            }
        }
    }
    return d;
}

using Eg = Edge<double>;

double solve() {
    double e = 1e-12;
    double xs, ys, xt, yt;
    ll N;
    cin >> xs >> ys >> xt >> yt;
    cin >> N;
    vector<double> X(N+2), Y(N+2), R(N+2), dst(N+2, 1e14);
    for ( int i = 1; i <= N; i++ ) {
        cin >> X[i] >> Y[i] >> R[i];
    }
    X[0] = xs, Y[0] = ys, R[0] = 0;
    X[N+1] = xt, Y[N+1] = yt, R[N+1] = 0;

    auto f_dist = [&](int a, int b) {
        double dx = X[a] - X[b], dy = Y[a] - Y[b];
        return max(0.0, sqrt(dx*dx+dy*dy) - R[a] - R[b]);
    };
    
    vector<vector<Eg>> G(N+2);
    for ( int i = 0; i < N+2; i++ ) {
        for ( int j = i; j < N+2; j++ ) {
            if ( i != j ) {
                double w = f_dist(i,j);
                G[i].emplace_back(j, w);
                G[j].emplace_back(i, w);
            }
        }
    }

    auto ans = dijkstra(G, 0);
    return ans[N+1];
}

int main() {
    cout.precision(15);
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}
