#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct UnionFind {
  const int n;
  V<> t; // root ? -sz : par
  UnionFind(int n) : n(n), t(n, -1) {}
  int find(int v) { return t[v] < 0 ? v : t[v] = find(t[v]); }
  void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (-t[u] < -t[v]) swap(u, v);
    t[u] += t[v];
    t[v] = u;
  }
  bool same(int u, int v) { return find(u) == find(v); }
  int size(int v) { return -t[find(v)]; }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  V<> b(n); for (auto&& e : b) cin >> e;
  a.push_back(accumulate(begin(a), end(a), 0, [](int init, int x) { return init ^ x; }));
  b.push_back(accumulate(begin(b), end(b), 0, [](int init, int x) { return init ^ x; }));
  auto _a = a, _b = b;
  sort(begin(_a), end(_a));
  sort(begin(_b), end(_b));
  if (_a != _b) return cout << -1 << '\n', 0;
  map< int, V<> > mp;
  for (int i = 0; i <= n; ++i) if (i == n or a[i] != b[i]) {
    mp[a[i]].push_back(i);
    mp[b[i]].push_back(i);
  }
  UnionFind uf(n + 1);
  for (const auto& e : mp) {
    for (int i : e.second) {
      uf.unite(e.second[0], i);
    }
  }
  int res = 0;
  set<int> se;
  for (int i = 0; i <= n; ++i) if (i == n or a[i] != b[i]) {
    if (se.count(uf.find(i))) continue;
    se.insert(uf.find(i));
    if (uf.same(i, n)) {
      res += uf.size(i) - 1;
    } else {
      res += uf.size(i) + 1;
    }
  }
  cout << res << '\n';
}
