#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int cnt[26];

int main() {
  int n;
  string s;
  cin >> n >> s;

  for (int i = 0; i < s.size(); i++) {
    cnt[s[i]-'a']++;
  }

  ll ans = 1;
  for (int i = 0; i < 26; i++) {
    ans *= cnt[i] + 1;
    ans %= MOD;
  }

  cout << ans - 1 << endl;
  return 0;
}
