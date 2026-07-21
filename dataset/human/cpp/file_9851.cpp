#include <bits/stdc++.h>
using namespace std;
int n;
char s[100010];
int cnt[30];
const int md = (int)1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> (s + 1);
  for (int i = 1; i <= n; ++i) ++cnt[s[i] - 'a' + 1];
  long long ans = 1;
  for (int i = 1; i <= 26; ++i)
    ans = ans * (cnt[i] + 1) % md;
  cout << (ans - 1 + md) % md;
  return 0;
}
