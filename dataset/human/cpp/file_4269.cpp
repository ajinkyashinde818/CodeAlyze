#include <cstdio>
#include <cstdlib>
#include <map>
#include <numeric>
#include <algorithm>

const int N = 200000 + 10;

int n, a[N], b[N];
int sorted[N], tot;

int anc[N];

int find(int x) { return anc[x] == x ? x : (anc[x] = find(anc[x])); }

bool init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[0] ^= a[i];
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]), b[0] ^= b[i];
  std::map<int, int> cnt;
  for (int i = 0; i <= n; ++i) ++cnt[a[i]], --cnt[b[i]];
  for (auto it : cnt) if (it.second) return false;
  tot = 0;
  for (int i = 1; i <= n; ++i) if (a[i] != b[i]) sorted[++tot] = a[i], sorted[++tot] = b[i];
  std::sort(sorted + 1, sorted + tot + 1);
  tot = std::unique(sorted + 1, sorted + tot + 1) - sorted - 1;
  auto f = [&] (int x) { return std::lower_bound(sorted + 1, sorted + tot + 1, x) - sorted; };
  for (int i = 1; i <= n; ++i) if (a[i] != b[i]) a[i] = f(a[i]), b[i] = f(b[i]);
  return true;
}

int main() {
  if (!init()) {
    puts("-1");
    return 0;
  }
  std::iota(anc, anc + tot + 1, 0);
  int ans = tot;
  for (int i = 1; i <= n; ++i) if (a[i] != b[i] && find(a[i]) != find(b[i])) anc[find(a[i])] = find(b[i]), --ans;
  for (int i = 1; i <= n; ++i) ans += (a[i] != b[i]);
  int p = std::lower_bound(sorted + 1, sorted + tot + 1, a[0]) - sorted;
  ans -= (0 < p && p <= tot && sorted[p] == a[0]);
  printf("%d\n", ans);
  return 0;
}
