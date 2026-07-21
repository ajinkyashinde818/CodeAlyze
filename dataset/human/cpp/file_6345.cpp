// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

// #undef DEBUG
// #define DEBUG
// DEBUG {{{
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <valarray>
#include <vector>
template < int n, class... T >
typename std::enable_if< (n >= sizeof...(T)) >::type __output_tuple(
    std::ostream &, std::tuple< T... > const &) {}
template < int n, class... T >
typename std::enable_if< (n < sizeof...(T)) >::type __output_tuple(
    std::ostream &os, std::tuple< T... > const &t) {
  os << (n == 0 ? "" : ", ") << std::get< n >(t);
  __output_tuple< n + 1 >(os, t);
}
template < class... T >
std::ostream &operator<<(std::ostream &os, std::tuple< T... > const &t) {
  os << "(";
  __output_tuple< 0 >(os, t);
  os << ")";
  return os;
}
template < class T, class U >
std::ostream &operator<<(std::ostream &os, std::pair< T, U > const &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template < class T >
std::ostream &operator<<(std::ostream &os, const std::stack< T > &a) {
  os << "{";
  for(auto tmp = a; tmp.size(); tmp.pop())
    os << (a.size() == tmp.size() ? "" : ", ") << tmp.top();
  os << "}";
  return os;
}
template < class T, class Container, class Compare >
std::ostream &operator<<(std::ostream &os,
    std::priority_queue< T, Container, Compare > a) {
  os << "{ (top) ";
  while(a.size()) os << a.top() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
template < class T, class Container >
std::ostream &operator<<(std::ostream &os, std::queue< T, Container > a) {
  os << "{ ";
  while(a.size()) os << a.front() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
#ifdef DEBUG
#if !defined(DEBUG_OUT)
// #define DEBUG_OUT std::cerr
#endif
#define dump(...)                                                                \
  [&]() {                                                                        \
    auto __debug_tap = std::make_tuple(__VA_ARGS__);                             \
    DEBUG_OUT << "[" << __LINE__ << "] " << #__VA_ARGS__ << " = " << __debug_tap \
    << std::endl;                                                      \
  }()
template < class T >
inline void dump2D(T &d, size_t sizey, size_t sizex) {
  for(size_t i = 0; i < sizey; i++) {
    DEBUG_OUT << "\t";
    for(size_t j = 0; j < sizex; j++)
      DEBUG_OUT << d[i][j] << (j + 1 == sizex ? "" : "\t");
    DEBUG_OUT << std::endl;
  }
}
template < class T >
inline void dump1D(T &d, size_t sizey) {
  for(size_t i = 0; i < sizey; i++) {
    DEBUG_OUT << d[i] << (i + 1 == sizey ? "" : " ");
  }
  DEBUG_OUT << std::endl;
}
template <
class T, class = typename std::iterator_traits< decltype(begin(T())) >::value_type,
      class = typename std::enable_if< !std::is_same< T, std::string >::value >::type >
      std::ostream &operator<<(std::ostream &os, const T &a) {
        os << "{";
        for(auto ite = begin(a); ite != end(a); ++ite)
          os << (ite == begin(a) ? "" : ", ") << *ite;
        os << "}";
        return os;
      }
#else
#define dump(...) ((void) 42)
#define dump2D(...) ((void) 42)
#define dump1D(...) ((void) 42)
template <
class T, class = typename std::iterator_traits< decltype(begin(T())) >::value_type,
      class = typename std::enable_if< !std::is_same< T, std::string >::value >::type >
      std::ostream &operator<<(std::ostream &os, const T &a) {
        for(auto ite = begin(a); ite != end(a); ++ite)
          os << (ite == begin(a) ? "" : " ") << *ite;
        return os;
      }
#endif
// }}}


/// --- Modulo Integer {{{ ///
#include <ostream>
template < long long mod = static_cast< long long >(1e9 + 7) >
struct ModuloInteger {
  static_assert(mod > 0, "mod must be positive");
  static_assert(mod <= 3037000499, "mod is too big");
  using integer = long long;
  static ModuloInteger unused;
  // math {{{
  static inline integer extgcd(integer a, integer b, integer &x, integer &y) {
    integer d;
    return b == 0 ? (x = a < 0 ? -1 : 1, y = 0, a < 0 ? -a : a)
      : (d = extgcd(b, a % b, y, x), y -= a / b * x, d);
  }
  static inline integer modinv(integer a) {
    integer x = 0, y = 0;
    extgcd(a, mod, x, y);
    if(x < 0)
      x += mod;
    else if(x == mod)
      x = 0;
    return x;
  }
  static inline integer modpow(integer a, long long b) {
    if(b < 0) b = -b, a = modinv(a);
    integer r = 1;
    a %= mod;
    while(b) {
      if(b & 1) r = r * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return r;
  }
  // }}}

  integer val;
  constexpr ModuloInteger() : val(0) {}
  constexpr ModuloInteger(integer t) {
    val = t % mod;
    if(val < 0) val += mod;
  }

private:
  // strict constructor
  constexpr ModuloInteger(integer t, int) : val(t) {}

public:
  template < class T >
    explicit operator T() {
      return T(val);
    }
  // operator bool() { return bool(val); }
  // ModuloInteger <arithmetic-operator>[=] ModuloInteger {{{
  ModuloInteger operator+(ModuloInteger const &rhs) const {
    ModuloInteger tmp = *this;
    tmp += rhs;
    return tmp;
  }
  ModuloInteger operator-(ModuloInteger const &rhs) const {
    ModuloInteger tmp = *this;
    tmp -= rhs;
    return tmp;
  }
  ModuloInteger operator*(ModuloInteger const &rhs) const {
    ModuloInteger tmp = *this;
    tmp *= rhs;
    return tmp;
  }
  ModuloInteger operator/(ModuloInteger const &rhs) const {
    ModuloInteger tmp = *this;
    tmp /= rhs;
    return tmp;
  }
  ModuloInteger &operator+=(ModuloInteger const &rhs) {
    val = val + rhs.val;
    if(val >= mod) val -= mod;
    return *this;
  }
  ModuloInteger &operator-=(ModuloInteger const &rhs) { return *this += -rhs; }
  ModuloInteger &operator*=(ModuloInteger const &rhs) {
    val = val * rhs.val % mod;
    return *this;
  }
  ModuloInteger &operator/=(ModuloInteger const &rhs) { return *this *= rhs.inv(); }
  // }}}
  // increment, decrement {{{
  ModuloInteger operator++(int) {
    ModuloInteger tmp = *this;
    val = val + 1;
    if(val >= mod) val = 0;
    return tmp;
  }
  ModuloInteger operator--(int) {
    ModuloInteger tmp = *this;
    val = val == 0 ? mod - 1 : val - 1;
    return tmp;
  }
  ModuloInteger &operator++() {
    val = val + 1;
    if(val >= mod) val = 0;
    return *this;
  }
  ModuloInteger &operator--() {
    val = val == 0 ? mod - 1 : val - 1;
    return *this;
  }
  // }}}
  ModuloInteger operator-() const { return ModuloInteger(val == 0 ? 0 : mod - val, 0); }
  // ModuloInteger <arithmetic-operator>[=] T {{{
  template < typename T >
    ModuloInteger operator+(T const &rhs) const {
      return ModuloInteger(val + rhs % mod);
    }
  template < typename T >
    ModuloInteger operator-(T const &rhs) const {
      return ModuloInteger(mod + val - rhs % mod);
    }
  template < typename T >
    ModuloInteger operator*(T const &rhs) const {
      return ModuloInteger(val * (rhs % mod));
    }
  template < typename T >
    ModuloInteger operator/(T const &rhs) const {
      return ModuloInteger(val * modinv(rhs));
    }
  template < typename T >
    ModuloInteger &operator+=(T const &rhs) {
      val = (mod + val + rhs % mod) % mod;
      return *this;
    }
  template < typename T >
    ModuloInteger &operator-=(T const &rhs) {
      val = (mod + val - rhs % mod) % mod;
      return *this;
    }
  template < typename T >
    ModuloInteger &operator*=(T const &rhs) {
      val = val * (mod + rhs % mod) % mod;
      return *this;
    }
  template < typename T >
    ModuloInteger &operator/=(T const &rhs) {
      val = val * modinv(rhs) % mod;
      return *this;
    }
  // }}}
  ModuloInteger inv() const { return ModuloInteger(modinv(val), 0); }
  ModuloInteger operator~() const { return inv(); }
  friend std::ostream &operator<<(std::ostream &os, ModuloInteger const &mv) {
    os << mv.val;
    return os;
  }
  // equality operator {{{
  ModuloInteger operator==(const ModuloInteger &a) const { return val == a.val; }
  ModuloInteger operator!=(const ModuloInteger &a) const { return val != a.val; }
  ModuloInteger operator==(const integer &a) const { return val == ModuloInteger(a); }
  ModuloInteger operator!=(const integer &a) const { return val != ModuloInteger(a); }
  // }}}
  // T <arithmetic-operator> ModuloInteger {{{
  friend constexpr ModuloInteger operator+(integer a, ModuloInteger const &mv) {
    return ModuloInteger(a % mod + mv.val);
  }
  friend constexpr ModuloInteger operator-(integer a, ModuloInteger const &mv) {
    return ModuloInteger(a % mod - mv.val);
  }
  friend constexpr ModuloInteger operator*(integer a, ModuloInteger const &mv) {
    return ModuloInteger((mod + a % mod) * mv.val % mod, 0);
  }
  friend constexpr ModuloInteger operator/(integer a, ModuloInteger const &mv) {
    return ModuloInteger((mod + a % mod) * modinv(mv.val) % mod, 0);
  }
  // }}}
  // power {{{
  ModuloInteger operator^(integer x) const { return pow(*this, x); }
  ModuloInteger &operator^=(integer x) {
    val = modpow(val, x);
    return *this;
  }
  friend ModuloInteger pow(ModuloInteger x, integer y) {
    return ModuloInteger(modpow(x.val, y), 0);
  }
  // }}}
};
template < long long mod >
ModuloInteger< mod > ModuloInteger< mod >::unused(mod, 0);
/// }}}--- ///

using modint = ModuloInteger<>;


void NO () {
  cout << 0 << endl;
  exit(0);
}

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int nn;
  cin >> nn;
  string s;
  cin >> s;
  for(auto &e : s) e = e == 'B' ? 1 : 0;
  int n = s.size();
  vector<int> a(n);
  a[0] = s[0];
  for(int i = 1; i < n; i++) a[i] = s[i] != s[i-1];
  dump(n);
  dump(a);

  int c = 0;
  modint ans = 1;
  for(int i = 0; i < n; i++) {
    dump(i, c);
    if(a[i] == 0) {
      ans *= c;
      c--;
      if(i + 1 < n) a[i+1] ^= 1;
    } else {
      // 1
      c++;
      a[i] ^= 1;
    }
  }
  if(c != 0) ans = 0;
  dump(ans);
  for(int i = 1; i <= nn; i++) ans *= i;
  cout << ans << endl;
  return 0;
}
