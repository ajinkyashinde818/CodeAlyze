// #include <bits/stdc++.h>
#include <iostream> // cin, cout, string
#include <algorithm> // sort, min/max, upper/lower_bound, transform, count/copy_if
#include <vector>
#include <utility> // pair, swap
#include <functional>
#include <iomanip> // setprecision
#include <map>
#include <set> // multiset
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
#include <queue> // priority_queue
#include <deque>
#include <bitset>
#include <array>
#include <list>
#include <forward_list>
#include <complex>
#include <ratio>
#include <cassert>
#include <numeric> // accumulate, itoa
#include <random> // mt19937
#include <iterator>

using namespace std;

// #define int long long

using i64 = int64_t;
using ll = long long;
using ld = long double;

template<typename T> using vec = vector<T>;
template<typename T> using mat = vec<vec<T>>;
template<typename T> using dic = unordered_map<string, T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>; // dijkstra
// template<typename T, typename U> using P = pair<T, U>;
// template<typename... Args> using func = function<Args...>;
// template<typename T> using pq = priority_queue<T>;

using pii = pair<int, int>;
using ppi = pair<pii, int>;
using pip = pair<int, pii>;
using ppp = pair<pii, pii>;

using vi = vec<int>;
using mi = mat<int>; // Graph
using vp = vec<pii>;

constexpr int IINF =  0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
// constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
constexpr long long MOD = 1e9+7;

#define _overload(_1,_2,_3,name,...) name
#define _rep1(i,a,b) for(int i=(a), _##i=(b);i<_##i;++i)
#define _rep2(i,n) _rep1(i,0,n)
#define _rep3(n) _rep2(i,n)
#define rep(...) _overload(__VA_ARGS__,_rep1,_rep2,_rep3)(__VA_ARGS__)
#define _rrep1(i,a,b) for(int i=(b)-1, _##i=(a);i>=_##i;--i)
#define _rrep2(i,n) _rrep1(i,0,n)
#define _rrep3(n) _rrep2(i,n)
#define rrep(...) _overload(__VA_ARGS__,_rrep1,_rrep2,_rrep3)(__VA_ARGS__)

#define each(i,a) for(auto&& i:a)
#define each2(i,a) for(const auto& i:a)

#define pb push_back
// emplace_back(*) == push_back(constructor(*))
#define eb emplace_back
#define pob pop_back
#define pf push_front
#define pof pop_front

#define np next_permutation
#define pp prev_permutation

// make_pair(A, B) == pair<T, U>(A, B)
#define mp make_pair
// mt(...) == tie(...)
#define mt make_tuple

#define ft first
#define sd second

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a).size()
#define rev(a) reverse(all(a))
#define rs(a,l) (a).resize(l)

#define upper(s) transform(all(s), (s).begin(), toupper)
#define lower(s) transform(all(s), (s).begin(), tolower)

#define sum(a) accumulate(all(a), 0)
#define elif else if
#define unless(a) if(!(a))
#define qt(a) #a

#define endl '\n'
#define dec(n) fixed << setprecision(n)
#define zfl(n)  setfill(‘0’) << setw(n)

template<typename T=int, T l=0, T r=(T)MOD>
auto rnd = bind(uniform_int_distribution<T>(l, r), mt19937(chrono::steady_clock::now().time_since_epoch().count()));

template<typename T> inline constexpr T gcd2(T a, T b) { if(a==0 || b==0) return 0; while(b) { a = a%b; swap(a, b); } return a; }
template<typename T> inline constexpr T extgcd2(T a, T b, T &x, T &y) { x = 1; y = 0; while (b) { T t = a / b; a -= t * b; swap(a, b); x -= t * y; swap(x, y); } return a; }
template<typename T> inline constexpr T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T> inline constexpr bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline constexpr bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

template<typename A, typename B> istream &operator>>(istream &is, pair<A, B> &p) { is >> p.first; is >> p.second; return is; }
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { os << p.first << " " << p.second; return os; }

template<typename T> istream &operator>>(istream &is, vector<T> &v) { for(auto&& x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for(int i=0; i<(int)v.size(); ++i) cout << v[i] << ( i+1 != (int)v.size() ? " " : "" ); return os; }

#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg> void __f(const char* name, const Arg& arg) { cerr << name << " : " << arg << endl; }
template <typename Arg, typename... Args> void __f(const char* names, const Arg& arg, const Args&... args)
{ const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg << " | "; __f(comma+1, args...); }

inline auto yes(const bool &c) { return c ? "yes" : "no"; }
inline auto Yes(const bool &c) { return c ? "Yes" : "No"; }
inline auto YES(const bool &c) { return c ? "YES" : "NO"; }
inline auto Possible(const bool &c) { return c ? "Possible" : "Impossible"; }
inline auto POSSIBLE(const bool &c) { return c ? "POSSIBLE" : "IMPOSSIBLE"; }

template<typename T=int64_t, T P=MOD> // P : prime
class Fp {
  private:
    T n;
    template<typename U> constexpr void set(const U &m) noexcept { n = cast(m); }
  public:
    static constexpr T mod = P;
    template<typename U> static constexpr T cast(const U &m) noexcept {
      T v = (T)m;
      v %= mod;
      if(v < 0) v += mod;
      return v;
    }
    static constexpr T cast(const Fp &m) noexcept { return m.get(); }
    template<typename U> static constexpr Fp inv(const U &m) noexcept {
      T x, y, d = [&x, &y](T a, T b) {
        x = 1; y = 0;
        while (b) {
          T t = a / b;
          a -= t * b; swap(a, b);
          x -= t * y; swap(x, y);
        }
        return a;
      }((T)m, mod);
      assert( d == 1 );
      return Fp(x);
    }
    constexpr Fp() noexcept : n(0) {}
    template<typename U> constexpr Fp(const U &m) noexcept { set(m); }
    constexpr T get() const noexcept { return n; }
    template<typename U> constexpr Fp &operator=(const U &m) noexcept { set(m); return *this; }
    template<typename U> constexpr Fp &operator+=(const U &m) noexcept { set( n + cast(m) ); return *this; }
    template<typename U> constexpr Fp &operator-=(const U &m) noexcept { set( n - cast(m) ); return *this; }
    template<typename U> constexpr Fp &operator*=(const U &m) noexcept { set( n * cast(m) ); return *this; }
    template<typename U> constexpr Fp &operator/=(const U &m) noexcept { set( n * inv(cast(m)) ); return *this; }
    template<typename U>constexpr Fp pow(U e) const noexcept {
      if(e==0) return Fp(1);
      else if(e < 0) return inv(pow(-e));
      else {
        Fp a = *this, r = 1;
        while (e > 0) {
          if (e & 1) r *= a;
          a *= a;
          e >>= 1;
        }
        return r;
      }
    }
    template<typename U> explicit constexpr operator U() const noexcept { return (U)n; }
    constexpr Fp operator+() const noexcept { return *this; }
    constexpr Fp operator-() const noexcept { return Fp(-n); }
    template<typename U, typename V> friend constexpr Fp operator+(const U &n, const V &m) noexcept { return Fp(n) += m; }
    template<typename U, typename V> friend constexpr Fp operator-(const U &n, const V &m) noexcept { return Fp(n) -= m; }
    template<typename U, typename V> friend constexpr Fp operator*(const U &n, const V &m) noexcept { return Fp(n) *= m; }
    template<typename U, typename V> friend constexpr Fp operator/(const U &n, const V &m) noexcept { return Fp(n) /= m; }
    friend constexpr istream &operator>>(istream &is, Fp &n) noexcept { T m; is >> m; n = m; return is; }
    friend constexpr ostream &operator<<(ostream &os, const Fp &n) noexcept { os << n.get(); return os; }
    template<typename U, typename V> friend constexpr bool operator==(const U &n, const V &m) noexcept { return Fp(m).get() == Fp(n).get(); }
    template<typename U, typename V> friend constexpr bool operator!=(const U &n, const V &m) noexcept { return !(n == m); }
};
using Mod = Fp<>;

constexpr int lim = 2*100000+7; // 2*10^5+7
using vb = vector<bool>;

int N;
vb b;

Mod solve() {
  rep(i, N) {
    b[2*i+1] = !b[2*i+1];
  }
  int L=0;
  Mod res = 1;
  rep(i, 2*N) {
    if(!b[i]) ++L;
    else {
      if(L<1) {
        res = 0;
        break;
      }
      res *= L;
      --L;
    }
  }
  if(L>0) res = 0;
  return res;
}

signed main() {
  cin.tie(nullptr); cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N;
  rs(b, 2*N);
  rep(i, 2*N) {
    char c; cin >> c;
    b[i] = (c == 'W');
  }

  Mod ans = solve();
  rep(i, 2, N+1) ans *= i; // 組み合わせ(N!)
  cout << ans << endl;
  // cout << b << endl;

  return 0;
}
