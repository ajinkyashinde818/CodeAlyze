#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

// ====================================================================

int main() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  ll s = 0, count = 0, m = INF;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    count += (v[i] < 0);
    m = min(m, abs(v[i]));
    s += abs(v[i]);
  }
  cout << ((count % 2 == 0) ? s : s - m * 2) << endl;
}
