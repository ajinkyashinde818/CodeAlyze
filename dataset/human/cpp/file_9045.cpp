#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

typedef long long ll;
ll MOD = 1000000007;

// a^p
// 2^3 = 2 * 2^2
// 2^2 = 2 * (2^1)
// 2^1 = 2
ll modpow(ll a, ll p, ll mod) {
  if (p == 0) return 1;

  if (p % 2 == 0) {
    ll half = modpow(a, p / 2, mod) % mod;
    return half * half % mod;
  } else {
    return a * modpow(a, p - 1, mod) % mod;
  }
}

// nCa を求める
ll modCombination(ll n, ll a, ll mod) {
  if (n - a < a) {
    return modCombination(n, n - a, mod);
  }

  ll denominator = 1;  // 分母
  ll numerator = 1;    // 分子

  for (ll i = 0; i < a; i++) {
    denominator *= a - i;
    numerator *= n - i;
    denominator %= mod;
    numerator %= mod;
  }

  return numerator * modpow(denominator, mod - 2, mod) % mod;
}

class UnionFind {
 private:
  vector<ll> parents;

 public:
  UnionFind(ll n) : parents(n, -1) {}

  bool issame(ll x, ll y) { return root(x) == root(y); }

  bool merge(ll x, ll y) {
    if (issame(x, y)) return false;

    ll rx = root(x);
    ll ry = root(y);
    if (parents[rx] > parents[ry]) swap(rx, ry);
    // サイズ情報を更新
    parents[rx] += parents[ry];
    // yの親を更新
    parents[ry] = rx;

    return true;
  }

  ll size(ll x) { return -parents[root(x)]; }

 private:
  ll root(ll x) {
    if (parents[x] < 0) return x;
    // 根の親の値に木の(-)サイズの情報を入れる
    return parents[x] = root(parents[x]);
  }
};

int main() {
  cout << fixed << setprecision(15);

  ll N, M;
  cin >> N >> M;

  vector<string> A(N);
  vector<string> B(N);

  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (ll i = 0; i < M; i++) {
    cin >> B[i];
  }

  for (ll i = 0; i < N - M + 1; i++) {
    for (ll j = 0; j < N - M + 1; j++) {
      // A includes B
      bool included = true;
      for (ll l = 0; l < M; l++) {
        for (ll m = 0; m < M; m++) {
          if (A[i + l][j + m] != B[l][m]) {
            included = false;
            break;
          }
        }
        if (!included) break;
      }

      if (included) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}
