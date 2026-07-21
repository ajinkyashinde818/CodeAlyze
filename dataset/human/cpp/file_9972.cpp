#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
int n;
string s;
ll ans;
ll cnt[30] = {};
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cnt[s[i]-'a']++;
  }
  ans = 1;
  for (int i = 0; i < 26; i++) {
    ans *= (cnt[i]+1);
    ans %= mod;
  }
  cout << (ans+mod-1) % mod << endl;
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/
