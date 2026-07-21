#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 5000000000000000000;

struct Edge {int to; double cost;};

int main() {
    ll xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    int N;
    cin >> N;
    vector<ll> x(N), y(N), r(N);
    rep(i, N) cin >> x[i] >> y[i] >> r[i];
    
    vector<vector<Edge>> G(N + 2);
    rep(i, N) {
        G[0].push_back(Edge{i + 1, max(sqrt((xs - x[i]) * (xs - x[i]) + (ys - y[i]) * (ys - y[i])) - r[i], 0.0)});
        G[i + 1].push_back(Edge{0, max(sqrt((xs - x[i]) * (xs - x[i]) + (ys - y[i]) * (ys - y[i])) - r[i], 0.0)});
        G[N + 1].push_back(Edge{i + 1, max(sqrt((xg - x[i]) * (xg - x[i]) + (yg - y[i]) * (yg - y[i])) - r[i], 0.0)});
        G[i + 1].push_back(Edge{N + 1, max(sqrt((xg - x[i]) * (xg - x[i]) + (yg - y[i]) * (yg - y[i])) - r[i], 0.0)});
    }
    rep(i, N) rep(j, N) {
        if (i == j) continue;
        G[i + 1].push_back(Edge{j + 1, max(sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - r[i] - r[j], 0.0)});
    }
    G[0].push_back(Edge{N + 1, sqrt((xs - xg) * (xs - xg) + (ys - yg) * (ys - yg))});
    G[N + 1].push_back(Edge{N, sqrt((xs - xg) * (xs - xg) + (ys - yg) * (ys - yg))});
    
    vector<double> dist(N + 2, 3000000000000000000.0);
    dist[0] = 0;
    vector<int> used(N + 2, 0);
    priority_queue<pair<double, int>> pq;
    pq.push(pair<double, int>{0, 0});
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        if (used[v]) continue;
        for (auto e : G[v]) {
            double alt = dist[v] + e.cost;
            if (alt < dist[e.to]) {
                dist[e.to] = alt;
                pq.push(pair<double, int>{-alt, e.to});
            }
        }
        used[v] = 1;
    }
    cout << fixed << setprecision(15) << dist[N + 1] << "\n";
    return 0;
}
