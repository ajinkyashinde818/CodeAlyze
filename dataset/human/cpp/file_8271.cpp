#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <assert.h>
#include <array>
#include <cstdio>
#include <cstring>
#include <random>
#include <functional>
#include <numeric>
#include <bitset>
#include <fstream>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

int N;
vector<int> G[100010];
int dist[100010];
vector<int> T;

void bfs() {
  queue<int> q;
  q.push(0);
  rep(i, N) dist[i] = inf;
  dist[0] = 0;
  while(!q.empty()) {
    auto p = q.front(); q.pop();
    T.push_back(p);
    for(auto e: G[p]) {
      if(dist[e] < inf) continue;
      dist[e] = dist[p] + 1;
      q.push(e);
    }
  }
}

int parent[22][100010];
int depth[100010];

void dfs(int v, int p, int d) {
  parent[0][v] = p;
  depth[v] = d;
  for(auto && e: G[v]) if(e != p) {
    dfs(e, v, d + 1);
  }
}

void init() {
  dfs(0, -1, 0);
  rep(k, 20) rep(v, N)
    if(parent[k][v] == -1)
      parent[k+1][v] = -1;
    else
      parent[k+1][v] = parent[k][parent[k][v]];
}

int lca(int u, int v) {
  if(depth[u] > depth[v])
    swap(u, v);
  rep(k, 22) if((depth[v] - depth[u]) >> k & 1) {
    v = parent[k][v];
  }
  if(u == v)
    return u;
  for(int k=21; k>=0; k--)
    if(parent[k][u] != parent[k][v])
      u = parent[k][u],
      v = parent[k][v];
  return parent[0][u];
}

int main() {

  cin >> N;

  rep(i, N - 1) {
    int x; cin >> x; x--;
    G[x].push_back(i+1);
  }

  init();
  bfs();

  ll ans = 0;
  REP(i, 1, T.size()) {
    int a = T[i - 1];
    int b = T[i];
    ans += dist[a] + dist[b] - 2 * dist[lca(a, b)];
  }

  cout << ans << endl;
  
  return 0;
}
