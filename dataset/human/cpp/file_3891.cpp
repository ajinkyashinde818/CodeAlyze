//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = int64_t;
using ull = uint64_t;

template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
    return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
    auto inner = make_vec_nd(init, rest...);
    return vector<decltype(inner)>(size, inner);
}

struct ListCostGraph {
    struct Edge {
        size_t from;
        size_t to;
        double cost;
    };
    vector<vector<Edge>> edges;
    
    ListCostGraph(size_t size) { edges.resize(size); }
    
    void add_edge(size_t from, size_t to, double cost) {
        edges[from].push_back(Edge{from, to, cost});
    }
    
    void add_edge_bidir(size_t a, size_t b, double cost) {
        add_edge(a, b, cost);
        add_edge(b, a, cost);
    }
    
    vector<double> dijkstra(size_t s) {
        // O(E logV)
        vector<double> dist(edges.size(), numeric_limits<double>::max());
        struct P {
            size_t vertex;
            double distance;
            P(size_t vertex, double distance)
            : vertex(vertex)
            , distance(distance) {}
        };
        auto compare = [](const P& lhs, const P& rhs) {
            return lhs.distance > rhs.distance;
        };
        priority_queue<P, vector<P>, decltype(compare)> que(compare);
        dist[s] = 0;
        que.push(P(s, 0));
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            size_t v = p.vertex;
            double d = p.distance;
            if (dist[v] < d) {
                continue;
            }
            for (int i = 0; i < edges[v].size(); i++) {
                const Edge& e = edges[v][i];
                double new_dist = dist[v] + e.cost;
                if (dist[e.to] <= new_dist) {    // eを使っても最短経路が改善しないとき
                    continue;
                }
                dist[e.to] = new_dist;
                que.push(P(e.to, new_dist));
            }
        }
        return dist;
    }
};

int main() {
    pair<ll, ll> start;
    pair<ll, ll> end;
    cin >> start.first >> start.second >> end.first >> end.second;
    ll N;
    cin >> N;
    struct Barrier {
        pair<ll, ll> pos;
        double radius;
        double dist(pair<ll, ll> pt) {
            double dist = sqrt(pow(pt.first - pos.first, 2.0)
                               + pow(pt.second - pos.second, 2.0));
            return max(0.0, dist - radius);
        }
        double dist(Barrier rhs) {
            double dist = sqrt(pow(rhs.pos.first - pos.first, 2.0)
                            + pow(rhs.pos.second - pos.second, 2.0));
            return max(0.0, dist - radius - rhs.radius);
        }
    };
    vector<Barrier> bars;
    for (ll i = 0; i < N; i++) {
        Barrier bar;
        cin >> bar.pos.first >> bar.pos.second >> bar.radius;
        bars.push_back(bar);
    }
    constexpr ll BARS_OFFSET = 2;
    ListCostGraph graph(bars.size() + BARS_OFFSET);
    graph.add_edge_bidir(0, 1, sqrt(pow(start.first - end.first, 2.0) + pow(start.second - end.second, 2.0)));
    for (ll b = 0; b < bars.size(); b++) {
        graph.add_edge_bidir(0, b+BARS_OFFSET, bars[b].dist(start));
        graph.add_edge_bidir(1, b+BARS_OFFSET, bars[b].dist(end));
    }
    for (ll b1 = 0; b1 < bars.size(); b1++) {
        for (ll b2 = b1 + 1; b2 < bars.size(); b2++) {
            graph.add_edge_bidir(b1+BARS_OFFSET, b2+BARS_OFFSET, bars[b1].dist(bars[b2]));
        }
    }
    vector<double> dist_map = graph.dijkstra(0);
    cout << fixed << setprecision(10) << dist_map[1] << endl;
}
