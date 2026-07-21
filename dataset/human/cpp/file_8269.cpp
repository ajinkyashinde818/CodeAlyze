#include<bits/stdc++.h>
using namespace std;
const int MAX_V = 100000;
const int MAX_LOG_V = 30;
vector<int> G[MAX_V];
int root;
int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];
 
void dfs(int v, int p, int d){
  parent[0][v] = p;
  depth[v] = d;
  for(int i=0;i<G[v].size();i++)
    if(G[v][i] != p) dfs(G[v][i], v, d+1);
}
 
void init(int n){
  dfs(root, -1, 0);
  for(int k=0;k+1<MAX_LOG_V;k++){
    for(int v=0;v<n;v++){
      if(parent[k][v] < 0) parent[k+1][v] = -1;
      else parent[k+1][v] = parent[k][parent[k][v]];
    }
  }
}
 
int lca(int u, int v){
  if(depth[u] > depth[v]) swap(u,v);
  for(int k=0;k<MAX_LOG_V;k++)
    if((depth[v] - depth[u]) >> k & 1)
      v = parent[k][v]; 
  if(u == v) return u;
  for(int k=MAX_LOG_V-1;k>=0;k--){
    if(parent[k][u] != parent[k][v]){
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}
int N;
typedef long long ll;
int main(){
  cin >> N;
  for(int i=1;i<N;i++){
    int p; cin >> p;
    --p;
    G[p].push_back( i );
  }
  init(N);
  vector<int> R;
  queue<int> q;
  q.push( 0 );
  while( !q.empty() ){
    int p = q.front(); q.pop();
    R.push_back( p );
    for(int i=0;i<(int)G[p].size();i++){
      int to = G[p][i];
      q.push( to );
    }    
  }
 
  ll res = 0;
  for(int i=0;i<(int)R.size()-1;i++){
    res += - 2 * depth[lca(R[i],R[i+1])] + depth[R[i]] + depth[R[i+1]];
  }
  cout << res << endl;
  
  
}
