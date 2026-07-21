#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  ll n, c;
  cin >> n >> c;
  vector<ll> x(n + 2), v(n + 2), l(n + 1), r(n + 1);
  for(int i = 1; i <= n; i++) cin >> x[i] >> v[i];
  x[n + 1] = c;
  for(int i = 1; i <= n; i++) {
    int ii = n + 1 - i;
    r[i] = v[i] - (x[i] - x[i - 1]);
    l[i] = v[ii] - (x[ii + 1] - x[ii]);
    r[i] += r[i - 1];
    l[i] += l[i - 1];
  }
  ll ans = 0;
  vector<ll> lma(n + 1), rma(n + 1);
  for(int i = 1; i <= n; i++) {
    lma[i] = max(lma[i - 1], l[i]);
    rma[i] = max(rma[i - 1], r[i]);
  }
  for(int i = 1; i <= n; i++) {
    ans = max(ans, l[i]);
    ans = max(ans, l[i] - (c - x[n + 1 - i]) + rma[n - i]);
    ans = max(ans, r[i]);
    ans = max(ans, r[i] - x[i] + lma[n - i]);
  }
  cout << ans << endl;
}
