#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const int MAX = 1005;
static const double INF = 1e18;

// ダイクストラ法 O(ElogV)
vector<pair<int, double>> G[MAX];
vector<double> dist; // 最短距離
// main関数からこれらを削除すること

void dijkstra(int n, int s) { // nは頂点数, sは開始頂点
  priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
  // first:最短距離 second:頂点の番号
  dist = vector<double>(n, INF); // 初期化
  dist[s] = 0; // 開始点の距離は0
  pq.push(make_pair(0, s));
  
  while (!pq.empty()) {
    pair<double, int> p = pq.top();
    pq.pop();
    int v = p.second;
    if (dist[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      pair<int, double> p2 = G[v][i];
      if (dist[p2.first] > dist[v] + p2.second) {
        dist[p2.first] = dist[v] + p2.second;
        pq.push(make_pair(dist[p2.first], p2.first));
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  double xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  
  int n;
  cin >> n;
  
  vector<vector<double>> v(n, vector<double>(3));
  for (int i = 0; i < n; i++) {
    cin >> v.at(i).at(0) >> v.at(i).at(1) >> v.at(i).at(2);
  }
  
  // vector<pair<int, double>> G[n + 2];
  
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      double dis = sqrt(pow(v.at(i).at(0) - v.at(j).at(0), 2) + pow(v.at(i).at(1) - v.at(j).at(1), 2));
      dis = max((double) 0, dis - (v.at(i).at(2) + v.at(j).at(2)));
      G[i].emplace_back(make_pair(j, dis));
      G[j].emplace_back(make_pair(i, dis));
    }
  }
  for (int i = 0; i < n; i++) {
    double dis = sqrt(pow(v.at(i).at(0) - xs, 2) + pow(v.at(i).at(1) - ys, 2));
    dis = max((double) 0, dis - v.at(i).at(2));
    G[i].emplace_back(make_pair(n, dis));
    G[n].emplace_back(make_pair(i, dis));
  }
  for (int i = 0; i < n; i++) {
    double dis = sqrt(pow(v.at(i).at(0) - xt, 2) + pow(v.at(i).at(1) - yt, 2));
    dis = max((double) 0, dis - v.at(i).at(2));
    G[i].emplace_back(make_pair(n + 1, dis));
    G[n + 1].emplace_back(make_pair(i, dis));
  }
  double dis = sqrt(pow(xs - xt, 2) + pow(ys - yt, 2));
  G[n].emplace_back(make_pair(n + 1, dis));
  G[n + 1].emplace_back(make_pair(n, dis));
  
  dijkstra(n + 2, n);
  
  cout << fixed << setprecision(10) << dist[n + 1] << '\n';
}
