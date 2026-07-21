#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> c(26);
  for (int i = 0; i < n; ++i) {
    c[s[i] - 'a'] += 1;
  }

  ll ans = 1;
  for (auto n : c)
    ans *= n + 1, ans %= mod;
  ans -= 1;

  cout << ans << endl;
}
