#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<ll> lsum(n, 0), rsum(n, 0);
  lsum[0] = a[0];
  rsum[n - 1] = a[n - 1];
  for (int i = 1; i < n; i++) {
    lsum[i] = lsum[i - 1] + a[i];
    rsum[n - 1 - i] = rsum[n - 1 - (i - 1)] + a[n - 1 - i];
  }

  ll ans = -1;
  for (int i = 0; i < n - 1; i++) {
    ll t = abs(lsum[i] - rsum[i + 1]);
    if (ans == -1) {
      ans = t;
    } else {
      ans = min(ans, t);
    }
  }

  cout << ans << endl;

  return 0;
}
