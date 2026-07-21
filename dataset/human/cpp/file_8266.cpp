#include <bits/stdc++.h>
using namespace std;
const int LOG = 20;
struct lowest_common_ancestor{
  vector<int> d;
  vector<vector<int>> next;
  lowest_common_ancestor(vector<int> p, vector<vector<int>> c){
    int n = p.size();
    d = vector<int>(n, -1);
    d[0] = 0;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : c[v]){
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
    next = vector<vector<int>>(LOG, vector<int>(n, -1));
    for (int i = 0; i < n; i++){
      next[0][i] = p[i];
    }
    for (int i = 1; i < LOG; i++){
      for (int j = 0; j < n; j++){
        if (next[i - 1][j] != -1){
          next[i][j] = next[i - 1][next[i - 1][j]];
        }
      }
    }
  }
  int lca(int v, int w){
    if (d[v] > d[w]){
      swap(v, w);
    }
    for (int i = 0; i < LOG; i++){
      if ((d[w] - d[v]) >> i & 1){
        w = next[i][w];
      }
    }
    if (v == w){
      return v;
    }
    for (int i = LOG - 1; i >= 0; i--){
      if (next[i][v] != next[i][w]){
        v = next[i][v];
        w = next[i][w];
      }
    }
    return next[0][v];
  }
  int dist(int v, int w){
    return d[v] + d[w] - d[lca(v, w)] * 2;
  }
};
int main(){
  int n;
  cin >> n;
  vector<int> p(n, -1);
  for (int i = 1; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<vector<int>> c(n);
  for (int i = 1; i < n; i++){
    c[p[i]].push_back(i);
  }
  for (int i = 0; i < n; i++){
    sort(c[i].begin(), c[i].end());
  }
  vector<int> bfs;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    bfs.push_back(v);
    for (int w : c[v]){
      Q.push(w);
    }
  }
  lowest_common_ancestor T(p, c);
  long long ans = 0;
  for (int i = 0; i < n - 1; i++){
    ans += T.dist(bfs[i], bfs[i + 1]);
  }
  cout << ans << endl;
}
