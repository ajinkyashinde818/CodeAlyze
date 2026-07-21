#include <stdio.h>
#include <algorithm>
#include <utility>
typedef long long ll;
using namespace std;

ll max(ll a, ll b) {
  return a > b ? a : b;
}

int main(void) {
  ll i, j, k, n, c, ans = 0, now;
  scanf("%lld%lld", &n, &c);
  pair<ll, ll> s[2 * n];
  ll max1[2 * n], max2[2 * n];
  ll dp[2 * n];
  for(i = 0; i < n; ++i) scanf("%lld%lld", &s[i].first, &s[i].second);
  sort(s, s + n);
  for(i = 0; i < n; ++i) s[i + n] = s[i];
  max1[n] = 0, max2[n] = 0;
  for(i = n; i < 2 * n; ++i) {
    now += s[i].second;
    ll tmp = now - s[i].first;
    if(i != n) max1[i] = max1[i - 1], max2[i] = max2[i - 1];
    if(max1[i] < tmp) max1[i] = tmp;
    if(max2[i] < tmp - s[i].first) max2[i] = tmp - s[i].first;
  }
  now = 0, max1[n - 1] = 0, max2[n - 1] = 0;
  for(i = n - 1; i >= 0; --i) {
    now += s[i].second;
    ll tmp = now + s[i].first - c;
    if(i != n - 1) max1[i] = max1[i + 1], max2[i] = max2[i + 1];
    if(max1[i] < tmp) max1[i] = tmp;
    if(max2[i] < tmp + s[i].first - c) max2[i] = tmp + s[i].first - c;
  }
  //for(i = 0; i < 2 * n; ++i) printf("%lld %lld\n", max1[i], max2[i]);
  for(i = 1; i < n; ++i) if(ans < max1[i] + max2[i + n - 1]) ans = max1[i] + max2[i + n - 1];
  for(i = 1; i < n; ++i) if(ans < max1[i + n - 1] + max2[i]) ans = max1[i + n - 1] + max2[i];
  for(i = 0; i < 2 * n; ++i) if(ans < max1[i]) ans = max1[i];
  printf("%lld\n", ans);
  return 0;
}
