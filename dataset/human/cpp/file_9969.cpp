#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MOD = 1e9 + 7;

int main() {
  int n;
  string s;
  cin >> n >> s;
  map<char, int> m;
  for (char c = 'a'; c <= 'z'; c++) m[c] = 0;
  for (int i = 0; i < n; i++) m[s[i]]++;
  ll ans = 1;
  for (auto e : m) {
    int num = e.second + 1;
    ans = ans * num % MOD;
  }
  ans -= 1;
  cout << ans << endl;
}
