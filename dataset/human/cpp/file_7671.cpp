#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll tot = 0;
  for (ll &i : a) {
    cin >> i;
    tot += i;
  }
  ll rs = a[0];
  ll ans = abs(rs - tot + rs);
  for (int i = 1; i < n-1; i++) {
    rs += a[i];
    ans = min(ans, abs(rs - tot + rs));
  }
  cout << ans << endl;
  return 0;
}
