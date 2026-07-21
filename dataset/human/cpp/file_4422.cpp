#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 50;

int tab[N];
int a[N], b[N], n, tot = 0;
int buc[N];

namespace Dsu {
  int fa[N], countLinks;
  inline void Init() {
    memset(fa, 0, sizeof fa); countLinks = 0;
  }
  inline int getf(int x) {
    return fa[x] ? fa[x] = getf(fa[x]) : x;
  }
  inline void U(int x, int y) {
    x = getf(x); y = getf(y);
    if (x != y) {
      fa[x] = y; countLinks ++;
    }
  }
}
using namespace Dsu;

vector <int> rec[N];

int cnt[N];
bool vv[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) {
    scanf("%d", &a[i]); tot ^= a[i]; tab[i] = a[i];
  }
  for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
  tab[n + 1] = tot;
  sort(tab + 1, tab + n + 2);
  tot = lower_bound(tab + 1, tab + n + 2, tot) - tab;
  buc[tot] ++;
  for (int i = 1; i <= n; i ++) {
    a[i] = lower_bound(tab + 1, tab + n + 2, a[i]) - tab;
    int lb = b[i];
    b[i] = lower_bound(tab + 1, tab + n + 2, b[i]) - tab;
    if (lb != tab[b[i]]) {
      puts("-1"); return 0;
    }
    buc[a[i]] ++; buc[b[i]] --;
    if (a[i] != b[i]) {
      rec[a[i]].push_back(i);
      rec[b[i]].push_back(i);
    }
  }
  for (int i = 1; i <= n + 1; i ++)
    if (buc[i] < 0) {
      puts("-1"); return 0;
    }
  for (int i = 1; i <= n + 1; i ++)
    if (rec[i].size()) {
      for (int j = 1; j < (int)rec[i].size(); j ++)
        U(rec[i][0], rec[i][j]);
    }
  for (int i = 1; i <= n; i ++) {
    cnt[getf(i)] ++;
    if (b[i] == tot) vv[getf(i)] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i ++)
    if (a[i] != b[i] && i == getf(i)) ans += cnt[i] - vv[i] + 1;
  printf("%d\n", ans);
  return 0;
}
