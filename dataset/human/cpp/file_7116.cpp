#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll X = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    X += a[i];
  }

  ll x  = 0;
  ll mn = LLONG_MAX;
  for (int i = 0; i < n - 1; i++) {
    x += a[i];
    ll y = X - x;

    mn = min(mn, abs(x - y));
  }
  cout << mn << endl;
}
