#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <iomanip>
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

class Direct_Graph {
    public:
    struct Edge { 
        int to; double cost;
    };
    std::vector<std::vector<Edge>> G;
    int node_num;
    Direct_Graph() {}
    Direct_Graph(const int node_num_in) {
        node_num = node_num_in;
        G.resize(node_num);
    }
    void add_edge(const int from, const int to, const double cost) {
        Edge edge; edge.to = to; edge.cost = cost;
        G[from].push_back(edge);
    }
    void add_edge_both(const int node1, const int node2, const double cost) {
        add_edge(node1, node2, cost);
        add_edge(node2, node1, cost);
    }

    std::vector<double> Dijkstra(int s, const double dist_inf) {
        std::vector<double> dist; dist.resize(node_num);
        for (int i = 0; i < dist.size(); i++) {
            dist[i] = dist_inf;
        }
        typedef std::pair<double, int> Pair;

        std::priority_queue <Pair, std::vector<Pair>, std::greater<Pair>> que;
        dist[s] = 0;
        que.push(Pair(0, s));

        while (!que.empty()) {
            Pair pair = que.top(); que.pop();
            int v = pair.second;
            if (dist[v] < pair.first) { continue; }
            for (Edge edge : G[v]) {
                if (dist[v] + edge.cost < dist[edge.to]) {
                    dist[edge.to] = dist[v] + edge.cost;
                    que.push(Pair(dist[edge.to], edge.to));
                }
            }
        }

        return dist;
    }
};

const int MAX_N = 1050;
const double MAX_DIST = 1000000000000.0;

Direct_Graph direct_graph = Direct_Graph(MAX_N);

int N;
long long xs, ys, xt, yt;
long long x[MAX_N], y[MAX_N], r[MAX_N];

double calc_dist(const int i, const int j) {
    double dist2 = (double)(x[i] - x[j]) * (x[i] - x[j]) + (double)(y[i] - y[j]) * (y[i] - y[j]);
    double dist = sqrt(dist2);
    return std::max(dist - r[i] - r[j], 0.0);
}

int main(int argc, char **argv) {
    std::cin >> xs >> ys >> xt >> yt;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> x[i] >> y[i] >> r[i];
    }
    N++;

    x[0] = xs; y[0] = ys; r[0] = 0;
    x[N] = xt; y[N] = yt; r[N] = 0;

    for (int i = 0; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            double dist = calc_dist(i, j);
            direct_graph.add_edge_both(i, j, dist);
        }
    }

    std::vector<double> dist = direct_graph.Dijkstra(0, MAX_DIST);
    std::cout << std::setprecision(12) << dist[N] << std::endl;
    

    return 0;
}
