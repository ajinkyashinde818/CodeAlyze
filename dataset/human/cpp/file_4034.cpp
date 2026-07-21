#include <cmath>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

struct Node {
  int id;
  double cost;
  Node() {}
  Node(int i, double c) : id(i), cost(c) {}
  friend bool operator < (const Node& lhs, const Node& rhs) { return lhs.cost > rhs.cost; };
  friend bool operator > (const Node& lhs, const Node& rhs) { return rhs < lhs; };
  friend bool operator <= (const Node& lhs, const Node& rhs) { return !(lhs > rhs); };
  friend bool operator >= (const Node& lhs, const Node& rhs) { return !(lhs < rhs); };
};

struct Point {
  ll x, y, r;
};

double dist[1002][1002];
double cost[1002];
bool visit[1002];

double INF = 1e60;
double distance(const Point& from, const Point& to) {
  return max(0.0, sqrt((from.x-to.x)*(from.x-to.x)+(from.y-to.y)*(from.y-to.y))-from.r-to.r);
}

void dijkstra(int n) {
  int s = 0;
  for (int i = 0; i < n+2; ++i) {
    cost[i] = INF;
  }
  cost[0] = 0;
  priority_queue<Node> pq;
  pq.push(Node(s, 0));
  while (!pq.empty()) {
    Node from = pq.top(); pq.pop();
    // cerr << from.id << " " << from.cost << endl;
    if (visit[from.id]) continue;
    visit[from.id] = true;
    for (int to = 0; to < n+2; ++to) {
      if (from.id == to || visit[to]) continue;
      double c = cost[from.id]+dist[from.id][to];
      if (c > cost[to]) continue;
      cost[to] = c;
      pq.push(Node(to, c));
    }
  }
}

int main() {
  int xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  int n;
  cin >> n;
  vector<Point> lp;
  lp.push_back((Point){xs, ys, 0});
  for (int i = 0; i < n; ++i) {
    int x, y, r;
    cin >> x >> y >> r;
    lp.push_back((Point){x, y, r});
  }
  lp.push_back((Point){xt, yt, 0});
  for (int i = 0; i < n+2; ++i) {
    for (int j = 0; j < n+2; ++j) {
      dist[i][j] = distance(lp[i], lp[j]);
      // cerr << i <<  " " << j << " " << dist[i][j] << endl;
    }
  }
  dijkstra(n);
  cout << setprecision(12) << cost[n+1] << endl;
}
