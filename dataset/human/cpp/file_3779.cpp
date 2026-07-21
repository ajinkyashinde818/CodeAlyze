#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <tuple>
#include <iomanip>

using namespace std;

template< typename T >
struct edge {
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;

template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, int s) {
    vector< T > dist(g.size(), numeric_limits< T >::max());
    dist[s] = 0;

    using Pi = pair< T, int >;
    priority_queue< Pi, vector< Pi >, greater< Pi > > que;
    que.emplace(dist[s], s);

    while(!que.empty()) {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e : g[idx]) {
            auto next_cost = cost + e.cost;
            if(dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}

int main(void) {
    long double sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int N;
    cin >> N;
    vector<long double> x(N+2), y(N+2), r(N+2);
    for(int i=1; i<=N; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    x[0] = sx;
    x[N+1] = tx;
    y[0] = sy;
    y[N+1] = ty;

    WeightedGraph<long double> g(N+2);
    for(int i=0; i<N+2; i++) {
        for(int j=0; j<N+2; j++) {
            if(i == j) continue;
            g[i].emplace_back(j, max(0.0L, hypotl(x[j]-x[i], y[j]-y[i]) - r[i] - r[j]));
        }
    }

    cout << setprecision(15);
    cout << dijkstra(g, 0).back() << endl;
    return 0;
}
