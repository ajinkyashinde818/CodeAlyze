#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll cnt = 0, sum = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a.at(i);
    if (a.at(i) < 0) {
      cnt++;
      sum -= a.at(i);
    }
    else sum += a.at(i);
  }
  if (cnt % 2 == 0) cout << sum << endl;
  else {
    for (ll i = 0; i < n; i++)
      if (a.at(i) < 0) a.at(i) *= - 1;
    sort(a.begin(), a.end());
    cout << sum - 2 * a.at(0) << endl;
  }
}
