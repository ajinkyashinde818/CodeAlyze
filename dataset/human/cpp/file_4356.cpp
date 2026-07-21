#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N],n,b[N],tmp,ans,cur,uni[N],sz[N],vis[N];
map<int,int> mp;
typedef pair<int,int> pii;
vector<int> vec;
template <typename tp>
void outputarr(tp *a,tp *b) {
  while (a != b)
    cerr << *a << ' ', ++ a;
  cerr << endl;
}
int getfa(int pos) {
  return pos == uni[pos] ? pos : uni[pos] = getfa(uni[pos]);
}
int main() {
  scanf("%d",&n);
  for (int i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]), tmp ^= a[i];
  a[0] = tmp;
  for (int i = 1 ; i <= n ; ++ i)
    scanf("%d",&b[i]);
  for (int i = 0 ; i <= n ; ++ i)
    ++ mp[a[i]];
  for (int i = 1 ; i <= n ; ++ i) {
    if (!mp.count(b[i]))
      return puts("-1"), 0;
    if (mp[b[i]] == 0) return puts("-1"), 0;
    mp[b[i]]--;
  }
  for (int i = 0 ; i <= n ; ++ i)
    if (mp[a[i]]) b[0] = a[i];
  for (int i = 0 ; i <= n ; ++ i)
    vec.push_back(a[i]);
  sort(vec.begin(),vec.end());
  vec.erase(unique(vec.begin(),vec.end()),vec.end());
  for (int i = 0 ; i <= n ; ++ i)
    a[i] = lower_bound(vec.begin(),vec.end(),a[i]) - vec.begin() + 1, \
      b[i] = lower_bound(vec.begin(),vec.end(),b[i]) - vec.begin() + 1;
  for (int i = 0 ; i <= n ; ++ i)
    uni[a[i]] = a[i];
  for (int i = 0 ; i <= n ; ++ i) {
    int x = getfa(a[i]), y = getfa(b[i]);
    if (x != y)
      uni[x] = y;
  }
  for (int i = 0 ; i <= n ; ++ i) {
    if (a[i] == b[i]) continue;
    ++ ans;
    ++ sz[getfa(a[i])];
  }
  for (int i = 0 ; i <= n ; ++ i) {
    if (a[i] == b[i]) continue;
    if (a[i] == getfa(a[i]) && !vis[a[i]]) {
      ++ ans;
      vis[a[i]] = 1;
    }
  }
  if (a[0] != b[0]) ans --;
  if (sz[getfa(a[0])] > 1) ans --;
  printf("%d\n",ans);
  return 0;
}
