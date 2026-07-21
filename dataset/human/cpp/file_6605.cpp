#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  ll mod = 1e9+7;
  ll acc = 0, carry = 0, ans = 1;
  for (int i = 0; i < n*2; i++) {
    int v = (s[i]=='B')^(i ? (s[i-1]=='B') : 0)^carry;
    if (v) {
      acc++;
      carry = 0;
    } else {
      (ans *= acc--) %= mod;
      if (acc < 0) ans = 0;
      carry = 1;
    }
  }
  if (acc) ans = 0;
  for (int i = 1; i <= n; i++)
    (ans *= i) %= mod;
  cout << ans << endl;
}
