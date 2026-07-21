#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  ll a;
  ll sum[200000];

  sum[0] = 0;
  for (ll i = 1; i <= n; i++) {
    cin >> a;
    sum[i] = sum[i - 1] + a;
  }

  ll minv = LLONG_MAX;
  for (ll i = 1; i < n; i++) {
    minv = min(minv, llabs(sum[n] - sum[i] - sum[i]));
  }
  cout << minv << endl;
  return 0;
}
