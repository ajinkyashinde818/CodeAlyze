#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string a;
  cin >> n >> a;
  map<int,int> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
  }
  int ans = 1;
  const int mod = 1e9 + 7;
  for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++) {
    ans = (1LL * ans * (it->second + 1)) % mod;
  }
  cout << ans - 1 << '\n';
  return 0;
}
