#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  string s;
  cin >> N >> s;
  const ll MOD = 1000000007;
  map<char,ll> mp;
  for (char c : s) mp[c] += 1;
  ll ans = 1;
  for (auto m : mp) {
    ans = ans * (m.second+1) % MOD;
  }
  cout << (ans-1)%MOD << endl;
}
