#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

const lli MAXN = 100005;
const lli LG_NMAX = 64;

vector<lli> child[MAXN];

struct Edge {
  int v, w;
};
typedef vector<vector<Edge> > Graph;

class LCA {
private:
  const static int LG_VMAX = 64;
  int n;
  vector<vector<int> > dpar;
  vector<int> depth;

public:
  LCA(const vector<int> &par, int root) {
    n = par.size();

    dpar = vector<vector<int> >(n, vector<int>(LG_VMAX, 0));
    for (int v = 0; v < n; ++v) dpar[v][0] = par[v];
    dpar[root][0] = root;
    for (int d = 1; d < LG_VMAX; ++d) {
      for (int v = 0; v < n; ++v) {
        dpar[v][d] = dpar[dpar[v][d-1]][d-1];
      }
    }

    depth = vector<int>(n, -1);
    depth[root] = 0;
    for (int v = 0; v < n; ++v) {
      if (depth[v] != -1) continue;
      stack<int> stk;
      stk.push(v);
      while (depth[dpar[stk.top()][0]] == -1) {
        stk.push(dpar[stk.top()][0]);
      }
      while (stk.size()) {
        depth[stk.top()] = depth[dpar[stk.top()][0]] + 1;
        stk.pop();
      }
    }
  }

  LCA(const Graph &g, int root) {
    n = g.size();
    
    vector<int> par(n, -1);
    par[root] = root;
    queue<int> que;
    que.push(root);
    while (que.size()) {
      int v = que.front();
      que.pop();
      for (int i = 0; i < g[v].size(); ++i) {
        int nv = g[v][i].v;
        if (par[nv] != -1) continue;
        par[nv] = v;
        que.push(nv);
      }
    }
    LCA(par, root);
  }

  int get(int a, int b) const {
    if (depth[a] != depth[b]) {
      if (depth[a] > depth[b]) swap(a, b);
      for (int d = LG_VMAX - 1; d >= 0; --d) {
        if (depth[a] <= depth[dpar[b][d]]) {
          b = dpar[b][d];
        }
      }
    }
    if (a == b) return a;
    for (int d = LG_VMAX - 1; d >= 0; --d) {
      if (dpar[a][d] != dpar[b][d]) {
        a = dpar[a][d];
        b = dpar[b][d];
      }
    }
    return dpar[a][0];
  }

  const vector<int>& getDepth() const {
    return depth;
  }
};

int main() {
  lli N;
  while (cin >> N) {
    fill(child, child + MAXN, vector<lli>());
    vector<int> par(N, 0);
    for (lli i = 1; i < N; ++i) {
      cin >> par[i];
      par[i]--;
      child[par[i]].push_back(i);
    }
    for (lli i = 0; i < N; ++i) {
      sort(child[i].begin(), child[i].end());
    }

    LCA lca(par, 0);
    const vector<int> &depth = lca.getDepth();
    lli res = 0, prev = 0;
    queue<lli> que;
    que.push(0);
    while (que.size()) {
      const lli v = que.front();
      que.pop();
      res += depth[prev] + depth[v] - depth[lca.get(prev, v)] * 2;
      prev = v;
      for (lli i = 0; i < child[v].size(); ++i) {
        que.push(child[v][i]);
      }
    }
    cout << res << endl;
  }
  return 0;
}
