#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}

template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << ' ' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

struct UndoableUnionFind {
  const int n;
  vector<int> t;
  vector< pair<int, int> > hist;
  UndoableUnionFind(int _n) : n(_n), t(n, -1) {}
  int find(int v) const { return t[v] < 0 ? v : find(t[v]); }
  void unite(int u, int v) {
    u = find(u), v = find(v);
    assert(u != v);
    if (-t[u] < -t[v]) swap(u, v);
    hist.emplace_back(u, t[u]);
    hist.emplace_back(v, t[v]);
    t[u] += t[v];
    t[v] = u;
  }
  void undo() {
    for (int _ = 0; _ < 2; ++_) {
      t[hist.back().first] = hist.back().second;
      hist.pop_back();
    }
  }
  bool same(int u, int v) const { return find(u) == find(v); }
  int size(int v) const { return -t[find(v)]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector< vector<int> > g(n);
  for (int _ = n - 1; _--; ) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  // vector<bool> white(n, true);
  vector< vector<int> > lr(n, vector<int>(1, 0));
  vector< vector<int> > qs(q);
  for (int t = 0; t < q; ++t) {
    int tp, v;
    cin >> tp >> v;
    --v;
    if (tp == 1) {
      lr[v].push_back(t);
      // white[v] = not white[v];
    } else {
      qs[t].push_back(v);
    }
  }
  int sz = 1 << __lg(2 * q - 1);
  vector< vector<int> > seg(2 * sz);
  for (int v = 0; v < n; ++v) {
    if (lr[v].size() & 1) {
      lr[v].push_back(q);
    }
    int m = lr[v].size();
    assert(~m & 1);
    DEBUG(v, lr[v]);
    for (int i = 0; i < m; i += 2) {
      int l = sz + lr[v][i], r = sz + lr[v][i + 1];
      while (l < r) {
        if (l & 1) {
          seg[l++].push_back(v);
        }
        if (r & 1) {
          seg[--r].push_back(v);
        }
        l >>= 1;
        r >>= 1;
      }
    }
  }
  DEBUG(seg);
  UndoableUnionFind uf(n);
  set<int> se;
  vector<int> res;
  auto dfs = [&](auto&& self, int k) -> void {
    int cnt = 0;
    for (int v : seg[k]) {
      se.insert(v);
    }
    for (int v : seg[k]) {
      for (int u : g[v]) {
        if (se.count(u) and not uf.same(v, u)) {
          uf.unite(v, u);
          ++cnt;
        }
      }
    }
    if (k < sz) {
      self(self, 2 * k);
      self(self, 2 * k + 1);
    } else if (k - sz < q) {
      for (int v : qs[k - sz]) {
        res.push_back(uf.size(v));
      }
    }
    while (cnt--) {
      uf.undo();
    }
    for (int v : seg[k]) {
      se.erase(v);
    }
  };
  dfs(dfs, 1);
  for (int e : res) {
    cout << e << '\n';
  }
}
