#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int cnt[26];
  ll ans = 1;
  for (int i = 0; i < 26; i++) {
    cnt[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (!cnt[i]) continue;

    ans *= (ll)(cnt[i] + 1);
    ans %= 1000000007;
  }

  cout << ans - 1 << endl;
}
