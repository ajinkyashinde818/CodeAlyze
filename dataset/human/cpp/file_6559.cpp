#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
const ll INF = (1ll << 60);

ll MOD = 1000000007;

ll permutation(ll x, ll y, ll mod) {
  ll ret = 1;
  for (ll i = 0; i < y; i++) {
    ret *= (x - i);
    ret %= mod;
  }
  return ret;
}

ll factorial(ll x, ll mod) { return permutation(x, x, mod); }

int main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;

  ll ans = 1;
  ll x = 0;

  for (ll i = 0; i < 2 * N; i++) {
    if (S[i] == 'B') {
      if (x % 2 == 0) {
        x++;
      } else {
        ans *= x;
        ans %= MOD;
        x--;
      }
    } else {
      if (x % 2 == 1) {
        x++;
      } else {
        ans *= x;
        ans %= MOD;
        x--;
      }
    }
    if (x == -1) {
      ans = 0;
    }
  }
  if (x != 0) {
    ans = 0;
  }

  cout << ans * factorial(N, MOD) % MOD << endl;
}
