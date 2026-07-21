#include <algorithm>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstdint>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using int64 = int64_t;

constexpr int64 MOD = 1000000007;

typedef double T;
const T INF = numeric_limits<T>::max() / 3;

struct Edge {
    int to;
    T cost;

    Edge() {}
    Edge(int a, T b): to(a), cost(b) {}
} ;

struct State {
    int pos;
    T cost;

    State() {}
    State(int a, T b): pos(a), cost(b) {}
} ;

class Graph {
public:
    vector<vector<Edge>> graph;
    vector<T> dist;
    int N;

    Graph() {}

    void init(int n) {
        graph.clear();
        graph.resize(N = n);
        dist.resize(N);
        fill(begin(dist), end(dist), INF);
    }

    void add_edge(int from, int to, T cost) {
        graph[from].push_back(Edge(to, cost));
    }

    void shortest_path_from(int start) {
        const static auto comp = [&](const State& a, const State& b) -> bool {
            return a.cost > b.cost;
        };

        priority_queue<State, vector<State>, decltype(comp)> pq(comp);

        fill(begin(dist), end(dist), INF);
        dist[start] = 0;

        pq.push(State(start, 0));

        while (!pq.empty()) {
            State s = pq.top(); pq.pop();
            if (s.cost > dist[s.pos]) {
                continue;
            }

            for (const Edge& e: graph[s.pos]) {
                if (e.cost + s.cost < dist[e.to]) {
                    dist[e.to] = e.cost + s.cost;
                    pq.push(State(e.to, dist[e.to]));
                }
            }
        }
    }

} ;

struct barrier {
    double x, y, r;
    barrier() {}
    barrier(double a, double b, double c): x(a), y(b), r(c) {}
} ;

double xs, ys, xt, yt;
int N;
barrier b[1010];

Graph g;

int main() {
    cin >> xs >> ys >> xt >> yt >> N;
    for (int j = 0; j < N; ++j) {
        int x, y, r; cin >> x >> y >> r;
        b[j].x = x; b[j].y = y; b[j].r = r;
    }

    g.init(N+2);

    for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
            if (j == k) { continue; }
            double d = max(0.0,
                    sqrt((b[j].x-b[k].x)*(b[j].x-b[k].x) + (b[j].y-b[k].y)*(b[j].y-b[k].y)) - b[j].r - b[k].r);
            g.add_edge(j, k, d);
            g.add_edge(k, j, d);
        }
    }

    // N: start
    for (int j = 0; j < N; ++j) {
        double d = max(0.0,
                sqrt((xs-b[j].x)*(xs-b[j].x) + (ys-b[j].y)*(ys-b[j].y)) - b[j].r);
        g.add_edge(j, N, d);
        g.add_edge(N, j, d);
    }
    // N+1: goal
    for (int j = 0; j < N; ++j) {
        double d = max(0.0,
                sqrt((xt-b[j].x)*(xt-b[j].x) + (yt-b[j].y)*(yt-b[j].y)) - b[j].r);
        g.add_edge(j, N+1, d);
        g.add_edge(N+1, j, d);
    }

    double d_st = sqrt(
            (xs-xt)*(xs-xt) + (ys-yt)*(ys-yt)
        );

    g.add_edge(N, N+1, d_st);
    g.add_edge(N+1, N, d_st);

    g.shortest_path_from(N);

    printf("%.12f\n", g.dist[N+1]);

    return 0;
}
