#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Dijkstra {
 public:
  int n;
  T INF = numeric_limits<T>::max();
  vector< vector< pair<int,T> > > g;
  vector<T> dis;
  vector<int> prev;
  
  Dijkstra(int _n) : n(_n) {
    g.resize(n);
  }

  void add_edge(int u, int v, T w) {
    assert(0 <= u && u < n && 0 <= v && v < n);
    assert(w >= 0);
    g[u].emplace_back(v, w);
  }

  vector<T> short_path(int s) {
    dis = vector<T>(n, INF);
    prev = vector<int>(n, -1);

    set< tuple<T,int,int> > bag; // cost, vertex, prev
    bag.insert(make_tuple(0, s, -1));
    while (bag.size()) {
      int u, v, p;
      T w, cost;
      tie(cost, u, p) = *bag.begin();
      bag.erase(bag.begin());
      if (dis[u] > cost) {
        dis[u] = cost;
        prev[u] = p;
        for (auto i : g[u]) {
          tie(v, w) = i;
          bag.insert(make_tuple(w + cost, v, u));
        }
      }
    }
    return dis;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int n;
  cin >> n;
  n += 2;
  vector<int> x(n), y(n), r(n);
  for (int i = 0; i < n - 2; i++) {
    cin >> x[i] >> y[i] >> r[i];
  }
  x[n - 2] = x1; y[n - 2] = y1;
  x[n - 1] = x2; y[n - 1] = y2;

  auto dis = [&](int i, int j) {
    double dx, dy, d;
    dx = x[i] - x[j];
    dy = y[i] - y[j];
    d = sqrt(dx * dx + dy * dy) - r[i] - r[j];
    return max(.0, d);
  };
  
  Dijkstra<double> g(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      g.add_edge(i, j, dis(i, j));
    }
  }

  double ans = g.short_path(n - 2)[n - 1];
  cout << fixed << setprecision(10) << ans << '\n';

  return 0;
}
