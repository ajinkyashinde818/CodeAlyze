#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using p = pair<ll, ll>;
constexpr ll INF = 1LL << 62;
ll MOD = 1e9 + 7;

ll N;
string S;
vector<ll> cnt;
ll uniq;

int main(void) {
  cnt = vector<ll>(26, 0);
  cin >> N >> S;
  for (auto&& s : S) {
    cnt[s - 'a']++;
  }

  ll ans = 0;

  for (auto c : cnt) {
    if (c == 0) {
      continue;
    }
    ans = ans + (ans * c) % MOD + c;
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}
