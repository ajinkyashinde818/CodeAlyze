// -----------------------------------
// author   : MatsuTaku
// country  : Japan
// created  : 07/14/20 20:57:13
// -----------------------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 1e9+7;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int n; cin>>n;
  string s; cin>>s;
  ll ans = 1;
  for (int m = 2; m <= n; m++)
    (ans *= m) %= MOD;
  int l = 1, r = 0;
  bool cl = true;
  for (int i = 1; i < 2*n; i++) {
    if (s[i] == s[i-1]) {
      cl = !cl;
    }
    if (!cl) {
      (ans *= l-r) %= MOD;
    }
    if (cl)
      l++;
    else
      r++;
  }
  if (cl or l != r or s[0] == 'W' or s[2*n-1] == 'W') {
    cout << 0 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
