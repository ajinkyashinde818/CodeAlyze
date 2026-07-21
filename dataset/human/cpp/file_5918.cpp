#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

long long x[N];
int v[N];
long long sa[N];
long long fa[N];
long long sb[N];
long long fb[N];

int main() {
  int n;
  long long m;
  scanf("%d %lld", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %d", x + i, v + i);
  }
  sa[0] = 0;
  fa[0] = 0;
  for (int i = 1; i <= n; ++i) {
    sa[i] = sa[i - 1] + v[i];
    fa[i] = max(fa[i - 1], sa[i] - x[i]);
  }
  sb[n + 1] = 0;
  fb[n + 1] = 0;
  for (int i = n; i >= 1; --i) {
    sb[i] = sb[i + 1] + v[i];
    fb[i] = max(fb[i + 1], sb[i] - m + x[i]);
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, sa[i] - x[i]);
    ans = max(ans, sa[i] - 2 * x[i] + fb[i + 1]);
  }
  for (int i = n; i >= 1; --i) {
    ans = max(ans, sb[i] - m + x[i]);
    ans = max(ans, sb[i] - 2 * m + 2 * x[i] + fa[i - 1]);
  }
  printf("%lld\n", ans);
}
