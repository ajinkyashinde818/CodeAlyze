#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MAX_N = 1e5 + 5;

int a [MAX_N];
int b [MAX_N];

vector<int> p;

int vis [MAX_N];
void dfs (int u, int src) {
  vis[u] = src;
  if (!vis[p[u]]) {
    dfs(p[u], src);
  }
}

int root [MAX_N];
int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);
  root[u] = v;
}

int main () {
  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
  }
  
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[0] ^= a[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[0] ^= b[i];
  }

  vector<int> sa, sb;
  for (int i = 0; i <= n; i++) {
    sa.push_back(a[i]);
    sb.push_back(b[i]);
  }
  sort(sa.begin(), sa.end());
  sort(sb.begin(), sb.end());
  if (sa != sb) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> va, vb;
  for (int i = 0; i <= n; i++) {
    if (i == 0 || a[i] != b[i]) {
      va.push_back(a[i]);
      vb.push_back(b[i]);
    }
  }

  map<int, int> seenb;
  map<pair<int, int>, int> pos;
  int K = va.size();
  for (int i = 0; i < K; i++) {
    if (seenb.count(vb[i]) == 0) {
      seenb[vb[i]] = 0;
    }
    pos[make_pair(vb[i], seenb[vb[i]])] = i;
    seenb[vb[i]]++;
  }

  map<int, int> seena;
  for (int i = 0; i < K; i++) {
    if (seena.count(va[i]) == 0) {
      seena[va[i]] = 0;
    }
    p.push_back(pos[make_pair(va[i], seena[va[i]])]);
    
    seena[va[i]]++;
  }

  /*
  for (int i = 0; i < K; i++) {
    cout << p[i] << " " ;
  }
  cout << endl;
  */

  vector<int> ids;
  for (int i = 0; i < K; i++) {
    if (!vis[i]) {
      dfs(i, i + 1);
      ids.push_back(i + 1);
    }
  }

  for (auto it = seenb.begin(); it != seenb.end(); it++) {
    int id = it->first;
    int cnt = it->second;
    for (int i = 0; i < cnt - 1; i++) {
      merge(vis[pos[make_pair(id, i)]], vis[pos[make_pair(id, i + 1)]]);
    }
  }

  int cc = 0;
  for (int id : ids) {
    if (find(id) == id) {
      cc++;
    }
  }

  cout << K + cc - 2 << endl;
}
