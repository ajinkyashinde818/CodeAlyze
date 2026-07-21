#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;
  map<int, int> m;
  for (int i = 0; i < N; i++) {
    m[s[i] - 'a']++;
  }
  ll ans = 1;
  for (int i = 0; i < 26; i++) {
    ans *= m[i] + 1;
    ans %= MOD;
  }
  ans -= 1;
  while (ans < 0) ans += MOD;
  cout << ans << endl;
}
