#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
  int n;
  cin >> n;

  ll SUM = 0, sum = 0;
  ll m = 1000000000000000000LL;

  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    SUM += v[i];
  }

  for (ll i = 0; i < n - 1; i++) {
    sum += v[i];
    m = min(m, abs(SUM - sum * 2));
  }

  cout << m << endl;
}
