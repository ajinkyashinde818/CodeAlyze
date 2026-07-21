#include <bits/stdc++.h>
using namespace std;

const int N = 101010;

int n, a[N], b[N], ans, res, tot, fa[N], vis[N];
vector<int> va, vb, V[N];
set<int> all;
map<int, int> mp;

int Find(int x) {
  return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void Merge(int x, int y) {
  if(x == y) return;
  ans++;
  x = Find(x);
  y = Find(y);
  if(x != y) {
    vis[x] = 1;
    vis[y] = 1;
    fa[x] = y;
  }
}

int main(void) {
  //freopen("duliu.in", "r", stdin);
  //freopen("duliu.out", "w", stdout);
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]), a[n + 1] ^= a[i];
  for(int i = 1; i <= n; i++)
    scanf("%d", &b[i]), b[n + 1] ^= b[i];
  for(int i = 1; i <= n + 1; i++) {
    va.push_back(a[i]);
    vb.push_back(b[i]);
    res += (a[i] != b[i]) && (i <= n);
  }
  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  
  for(int i = 0; i <= n; i++) {
    if(va[i] != vb[i])
      return puts("-1"), 0;
    if(mp.find(va[i]) == mp.end())
      mp[va[i]] = ++tot;
  }

  for(int i = 1; i <= tot; i++)
    fa[i] = i;

  for(int i = 1; i <= n; i++)
    Merge(mp[a[i]], mp[b[i]]);
  
  for(int i = 1; i <= tot; i++)
    if(vis[i] && fa[i] == i)
      ans++;
  if(vis[mp[a[n + 1]]])
    ans--;
  
  cout << ans << endl;
  return 0;
}
