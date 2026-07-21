#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  string s;
  cin >> n >> s;

  vector < char > d (2 * n);
  d[0] = 'L';
  int cnt = 1;
  for (int i = 1; i < 2 * n; i++) {
    if (s[i] == s[i - 1]) {
      if (d[i - 1] == 'L') {
        d[i] = 'R';
      } else {
        d[i] = 'L';
      }
    } else {
      d[i] = d[i - 1];
    }

    if (d[i] == 'L') cnt++;
    else cnt--;
  }

  if (cnt != 0 || s[0] != 'B' || s[2 * n - 1] != 'B') {
    cout << 0 << '\n';
    return 0;
  }

  ll ans = 1;
  for (int i = 0; i < 2 * n; i++) {
    if (d[i] == 'R') ans = (ans * cnt) % mod;
    if (d[i] == 'L') cnt++;
    else cnt--;
  }

  for (int i = 1; i <= n; i++) ans = (ans * i) % mod;

  cout << ans << '\n';
}
