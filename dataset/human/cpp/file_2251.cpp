#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()
#define sortAl(v) sort(all(v))
#define sortAlr(v)          \
  sort(v.begin(), v.end()); \
  reverse(v.begin(), v.end())

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T &a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T &a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
#define INF LLONG_MAX

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n;
  cin >> n;

  vll a(n);
  rep(i, n) {
    cin >> a[i];
  }

  ll minus_cnt = 0;
  bool exist_zero = false;

  rep(i, n) {
    if (a[i] < 0) {
      minus_cnt++;
    }
    if (a[i] == 0) {
      exist_zero = true;
    }
  }

  rep(i, n) {
    a[i] = abs(a[i]);
  }

  if (minus_cnt % 2 && !exist_zero) {
    auto it = min_element(all(a));
    *it *= -1;
  }

  ll ans = accumulate(all(a), 0ll);

  cout << ans << endl;

  return 0;
}
