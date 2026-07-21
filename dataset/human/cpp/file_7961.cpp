#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll total = 0;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    total += a[i];
  }

  ll ans = (ll)1e18;
  ll sum = 0;
  for (int i = 0; i < n - 1; i++) {
    sum += a[i];
    ans = min(ans, abs(total - 2 * sum));
  }

  cout << ans << endl;
  return 0;
}
