#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 1e5, MAX_LOG_V = 20;
vector<int> G[MAX_V];
int parent[MAX_LOG_V][MAX_V], depth[MAX_V];
vector< vector<int> > D(MAX_V);

void dfs(int v, int p, int d){
  parent[0][v] = p;
  depth[v] = d;
  D[d].push_back(v);
  for(int i = 0; i < G[v].size(); ++i){
    if(G[v][i] != p) dfs(G[v][i], v, d + 1);
  }
}

void init(int V, int root){
  dfs(root,-1,0);
  for(int k = 0; k + 1 < MAX_LOG_V; ++k){
    for(int v = 0; v < V; ++v){
      if(parent[k][v] < 0) parent[k + 1][v] = -1;
      else parent[k + 1][v] = parent[k][parent[k][v]];
    }
  }
}

int lca(int u, int v){
  if(depth[u] > depth[v]) swap(u, v);
  for(int k = 0; k < MAX_LOG_V; ++k){
    if((depth[v] - depth[u]) >> k & 1){
      v = parent[k][v];
    }
  }
  if(u == v) return u;
  for(int k = MAX_LOG_V - 1; k >= 0; --k){
    if(parent[k][u] != parent[k][v]){
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}

long long int solve(vector<int> &P, int root){
  int n = P.size();
  for(int i = 1; i < n; ++i){
    G[i].push_back(P[i]);
    G[P[i]].push_back(i);
  }
  for(int i = 0; i < n; ++i) sort(G[i].begin(), G[i].end());
  init(n, root);
  long long int ret = 0;
  //for(int i = 0; i < n; ++i) cout << depth[i] << " "; cout << endl;
  vector<int> order;
  int t = n;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < D[i].size(); ++j){
      order.push_back(D[i][j]);
      --t;
    }
    if(t == 0) break;
  }
  for(int i = 1; i < n; ++i){
    int u = order[i], v = order[i - 1], l = lca(u,v);
    ret += depth[u] + depth[v] - 2*depth[l];
  }
  return ret;
}

int main(){
  int n;
  cin >> n;
  vector<int> P(n);
  P[0] = -1;
  for(int i = 1; i < n; ++i){
    cin >> P[i];
    --P[i];
  }
  cout << solve(P,0) << endl;
  return 0;
}
