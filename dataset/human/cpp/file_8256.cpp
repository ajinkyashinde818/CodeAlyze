#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_V = 100010;
const int MAX_LOG_V = 20;
int root = 0;

int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];

using int64 = long long;
vector<int> G[MAX_V];

void dfs(int v, int p, int d) {
  parent[0][v] = p;
  depth[v] = d;
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] != p)
      dfs(G[v][i], v, d + 1);
  }
}

void init(int V) {
  dfs(root, -1, 0);
  for (int k = 0; k + 1 < MAX_LOG_V; k++) {
    for (int v = 0; v < V; v++) {
      if (parent[k][v] < 0)
        parent[k + 1][v] = -1;
      else
        parent[k + 1][v] = parent[k][parent[k][v]];
    }
  }
}

int lca(int u, int v) {
  if (depth[u] > depth[v])
    swap(u, v);
  for (int k = 0; k < MAX_LOG_V; k++) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if (u == v)
    return u;
  for (int k = MAX_LOG_V - 1; k >= 0; k--) {
    if (parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}

int main() {
  int N;
  cin >> N;
  for (int i = 1; i < N; i++) {
    int p;
    cin >> p;
    p--;
    G[p].push_back(i);
  }
  init(N);

  vector<int> ord;
  queue<int> q;
  ord.push_back(0);
  q.push(0);
  while (q.size()) {
    int v = q.front();
    q.pop();
    vector<int> nxt;
    for (int u : G[v]) {
      nxt.push_back(u);
    }
    sort(nxt.begin(), nxt.end());
    for (int u : nxt) {
      ord.push_back(u);
      q.push(u);
    }
  }

  int64 ans = 0;
  for (int i = 0; i < N - 1; i++) {
    int cur = ord[i];
    int nxt = ord[i + 1];
    int l = lca(cur, nxt);
    ans += depth[cur] + depth[nxt] - 2 * depth[l];
  }
  cout << ans << endl;
}
