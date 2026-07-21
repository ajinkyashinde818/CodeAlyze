#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  int n;
  ll sum = 0, x = 0, ans = INFL;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    x += a[i];
    if (i + 1 < n) ans = min(ans, abs(sum - 2 * x));
  }
  cout << ans << endl;
}
