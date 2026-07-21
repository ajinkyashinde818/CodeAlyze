/* dijkstra.cpp
    ダイクストラ法で、ある頂点から各頂点への最短距離を求めるアルゴリズム
    負の辺が含まれる場合はうまく計算出来ないので、ベルマンフォード法を用いる

    verified: AOJ GRL_1_A
        http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    long long to;
    double cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<double, int>;
const double INF = (double)(1LL << 60);

/* dijkstra(G,s,dis,prev)
    入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
    計算量：O(|E|log|V|)
    副作用：dis, prevが書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<double> &dis, vector<int> &prev) {
    int N = G.size();
    dis.resize(N, INF);
    prev.resize(N, -1);
    priority_queue<P, vector<P>, greater<P>> pq;  // the least element is top. first:cost, second: node
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();  // the least element
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {
                dis[e.to] = dis[v] + e.cost;
                prev[e.to] = v;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

/* get_path(prev, t)
    入力：dijkstra で得た prev, ゴール t
    出力： t への最短路のパス
*/
vector<int> get_path(const vector<int> &prev, int t) {
    vector<int> path;
    for (int cur = t; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int N;
    pair<double, double> s, t;
    cin >> s.first >> s.second >> t.first >> t.second;
    cin >> N;
    Graph G(N + 2);

    vector<double> x(N), y(N), r(N);
    for (int i = 0; i < N; i++) {
        cin >> x.at(i) >> y.at(i) >> r.at(i);
    }

    double d;

    // s,t間
    d = sqrt((s.first - t.first) * (s.first - t.first) + (s.second - t.second) * (s.second - t.second));
    G[N + 1].push_back({0, d});
    G[0].push_back({N + 1, d});

    // sと円, tと円
    for (int i = 0; i < N; i++) {
        d = sqrt((s.first - x[i]) * (s.first - x[i]) + (s.second - y[i]) * (s.second - y[i]));
        d = max(d - r[i], 0.0);
        G[0].push_back({i + 1, d});
        G[i + 1].push_back({0, d});
        d = sqrt((t.first - x[i]) * (t.first - x[i]) + (t.second - y[i]) * (t.second - y[i]));
        d = max(d - r[i], 0.0);
        G[N + 1].push_back({i + 1, d});
        G[i + 1].push_back({N + 1, d});
    }

    // 円同士
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            d = max(d - r[i] - r[j], 0.0);
            G[j + 1].push_back({i + 1, d});
            G[i + 1].push_back({j + 1, d});
        }
    }

    vector<double> dis;
    vector<int> prev;
    dijkstra(G, 0, dis, prev);
    cout << setprecision(15) << dis[N + 1] << endl;

    return 0;
}
