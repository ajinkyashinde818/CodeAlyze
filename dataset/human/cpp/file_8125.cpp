#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  ll sum = 0;
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  ll x = 0;
  ll y = sum;

  ll ans = INT_MAX;

  for (ll i = 0; i < n - 1; i++) {
    x += a[i];
    y -= a[i];
    ans = min(ans, abs(x - y));
  }
  cout << ans << endl;
}
