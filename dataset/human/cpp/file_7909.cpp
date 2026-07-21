#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll x = a[0];
  ll y = accumulate(a.begin() + 1, a.end(), 0ll);
  ll ans = abs(x - y);
  for (int i = 1; i < n - 1; i++) {
    x += a[i];
    y -= a[i];
    ans = min(ans, abs(x - y));
  }
  cout << ans << endl;
}
