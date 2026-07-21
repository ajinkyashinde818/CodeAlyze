#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <bitset>
#include <cmath>
#include <random>
#include "list"

using namespace std;
using ll = long long;
using ull = unsigned long long;
//const ll mod = 998244353;
const ll mod = 1000000007;
const int inf = 1e9;
const ll linf = 1e18;
const int DX[] = {1, -1, 0, 0};
const int DY[] = {0, 0, 1, -1};


#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep_from(i, j, n) for (ll i = (j); i < (n); ++i)
#define rep_rev(i, n) for (ll i = n-1; i >= 0; --i)
#define rep_from_rev(i, j, n) for (ll i = n-1; i >= j; --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) ll(x.size())

template<typename T>
inline T chmax(T &a, const T b) { return a = (a < b) ? b : a; }

template<typename T>
inline T chmin(T &a, const T b) { return a = (a > b) ? b : a; }

ll power(ll base, ll exponent) {
  if (exponent % 2) {
    return power(base, exponent - 1) * base % mod;
  } else if (exponent) {
    ll root_ans = power(base, exponent / 2);
    return root_ans * root_ans % mod;
  } else { return 1; }
}

ll inverse(ll x) { return power(x, mod - 2); }
ll gcd(ll a, ll b) {
  if (a < b) gcd(b, a);
  ll r;
  while (r = a % b) {
    a = b;
    b = r;
  }
  return b;
}

template<typename T>
ll sum(T begin, T end) { return accumulate(begin, end, 0ll); }

template<typename T>
struct combination {
    vector<ll> fact, inv;

    combination(int sz) : fact(sz + 1), inv(sz + 1) {
      fact[0] = 1;
      for (int i = 1; i <= sz; i++) { fact[i] = fact[i - 1] * i % mod; }
      inv[sz] = power(fact[sz], mod - 2);
      for (int i = sz - 1; i >= 0; i--) { inv[i] = inv[i + 1] * (i + 1) % mod; }
    }

    T C(int p, int q) const {
      if (q < 0 || p < q) return 0;
      return T(fact[p] * inv[q] % mod * inv[p - q] % mod);
    }

    T P(int p, int q) const {
      if(p < 0 || p < q) return 0;
      return T(fact[p] * inv[p - q] % mod);
    }
};

using Pair = pair<int, int>;
using LPair = pair<ll, ll>;

template<ll Modulus>
struct ModInt {
    ll a;

    constexpr ModInt(const ll x = 0) noexcept: a((x % mod + mod) % mod) {}

    constexpr ll &value() noexcept { return a; }

    constexpr const ll &value() const noexcept { return a; }

    constexpr ModInt operator+(const ModInt x) const noexcept {
      return ModInt(*this) += x;
    }

    constexpr ModInt operator-(const ModInt x) const noexcept {
      return ModInt(*this) -= x;
    }

    constexpr ModInt operator*(const ModInt x) const noexcept {
      return ModInt(*this) *= x;
    }

    constexpr ModInt operator/(const ModInt x) const noexcept {
      return ModInt(*this) /= x;
    }

    constexpr ModInt &operator+=(const ModInt x) noexcept {
      a += x.a;
      if (a >= Modulus) {
        a -= Modulus;
      }
      return *this;
    }

    constexpr ModInt &operator-=(const ModInt x) noexcept {
      if (a < x.a) {
        a += Modulus;
      }
      a -= x.a;
      return *this;
    }

    constexpr ModInt &operator*=(const ModInt x) noexcept {
      a = a * x.a % Modulus;
      return *this;
    }

    constexpr ModInt &operator/=(ModInt x) noexcept {
      ll exp = Modulus - 2;
      while (exp) {
        if (exp % 2) {
          *this *= x;
        }
        x *= x;
        exp /= 2;
      }
      return *this;
    }

    constexpr ModInt operator-() noexcept {
      return ModInt(-a);
    }

    friend ostream &operator<<(ostream &os, const ModInt &m) {
      os << m.a;
      return os;
    }
};

using mint = ModInt<mod>;

int main() {
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i ,n) cin >> a[i];
  rep(i ,n) cin >> b[i];
  map<int, int> c, d;
  rep(i, n) {
    c[a[i]]++;
    d[b[i]]++;
  }
  priority_queue<Pair> qa,qb;
  for(auto p: c) {
    qa.emplace(p.second, p.first);
  }
  for(auto p: d) {
    qb.emplace(p.second, p.first);
  }
  rep(i, n+1) {
    if(c[i] + d[i] > n) {
      cout << "No" << endl;
      return 0;
    }
  }
  vector<vector<int>> z(n+1);
  rep(i, n-2) {
    auto x = qa.top();qa.pop();
    auto y = qb.top();qb.pop();
    if(x.second != y.second) {
      z[x.second].push_back(y.second);
      qa.emplace(x.first-1, x.second);
      qb.emplace(y.first-1, y.second);
    }
    else {
      auto e = qb.top();qb.pop();
      z[x.second].push_back(e.second);
      qa.emplace(x.first-1, x.second);
      qb.emplace(y.first, y.second);
      qb.emplace(e.first-1, e.second);
    }
  }
  {
    auto x1 = qa.top();qa.pop();
    auto x2 = qa.top();qa.pop();
    auto y1 = qb.top();qb.pop();
    auto y2 = qb.top();qb.pop();
    if(x1.second != y1.second && x2.second != y2.second) {
      z[x1.second].push_back(y1.second);
      z[x2.second].push_back(y2.second);
    }
    else {
      z[x1.second].push_back(y2.second);
      z[x2.second].push_back(y1.second);
    }
  }
  vector<int> ans;
  rep(i, n+1) {
    ans.insert(ans.end(), all(z[i]));
  }
  cout << "Yes" << endl;
  rep(i, n) cout << ans[i] << " ";cout << endl;
}
