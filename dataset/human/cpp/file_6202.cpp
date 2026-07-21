#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long c;
  scanf("%d %lld", &n, &c);
  vector<long long> x(n);
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld %d", &x[i], &v[i]);

  vector<long long> suf(n, v.back());
  vector<long long> suf_max(n, v.back() - (c - x.back()));
  for (int i = n - 2; i >= 0; --i) {
    suf[i] = suf[i + 1] + v[i];
    suf_max[i] = max(suf[i] - (c - x[i]), suf_max[i + 1]);
  }

  vector<long long> pref(n, v[0]);
  vector<long long> pref_max(n, v[0] - x[0]);
  for (int i = 1; i < n; ++i) {
    pref[i] = pref[i - 1] + v[i];
    pref_max[i] = max(pref[i] - x[i], pref_max[i - 1]);
  }

  long long z = accumulate(v.begin(), v.end(), 0LL);
  long long ans = max({0LL, z - (c - x[0]), z - x[n - 1]});

  long long s = 0;
  for (int i = 0; i < n - 1; ++i) {
    s += v[i];
    ans = max(ans, s - x[i]);
    ans = max(ans, s - 2 * x[i] + suf_max[i + 1]);
  }

  s = 0;
  for (int i = n - 1; i >= 1; --i) {
    s += v[i];
    ans = max(ans, s - (c - x[i]));
    ans = max(ans, s - 2 * (c - x[i]) + pref_max[i - 1]);
  }

  printf("%lld\n", ans);
  return 0;
}
