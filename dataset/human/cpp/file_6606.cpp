#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr ll INF = 1ll << 55;

template <typename T> inline constexpr bool chmin(T &a, T b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <typename T> inline constexpr bool chmax(T &a, T b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}

// multi-dimensional vector (require c++14)
template <typename T, typename U>
static inline vector<U> make_nd_vector(T &&n, U &&val) noexcept {
  static_assert(is_integral<T>::value,
                "[make_nd_vector] 1st argument must be an integer type");
  return vector<U>(forward<T>(n), forward<U>(val));
}
template <typename T, typename... Args>
static inline decltype(auto) make_nd_vector(T &&n, Args &&... args) noexcept {
  static_assert(is_integral<T>::value,
                "[make_nd_vector] 1st argument must be an integer type");
  return vector<decltype(make_nd_vector(forward<Args>(args)...))>(
      forward<T>(n), make_nd_vector(forward<Args>(args)...));
}
//
// Print from Iterator
template <typename ite>
void print_ite(ite start, ite end, char sp = ' ', char en = '\n') {
  for (auto i = start; i != end; i++)
    cout << *i << sp;
  cout << en;
}
//
inline void Yes(bool condition) { cout << (condition ? "Yes\n" : "No\n"); }

namespace mod {
using u64 = uint_fast64_t;
template <u64 MOD> class modInt {

private:
  u64 _a;

public:
  constexpr modInt(const long long x = 0) : _a(((x % MOD) + MOD) % MOD) {}
  constexpr inline u64 value() const { return _a; }
  constexpr modInt pow(u64 p) const {
    if (p == 0)
      return modInt(1);
    if (p % 2 == 0) {
      modInt d = pow(p / 2);
      return d * d;
    } else {
      return *this * pow(p - 1);
    }
  }
  constexpr modInt inverse() const { return pow(MOD - 2); }
  constexpr modInt &operator+=(const modInt x) {
    _a += x.value();
    if (_a >= MOD) {
      _a -= MOD;
    }
    return *this;
  }
  constexpr modInt &operator-=(const modInt x) {
    if (_a < x.value()) {
      _a += MOD;
    }
    _a -= x.value();
    return *this;
  }
  constexpr modInt &operator*=(const modInt x) {
    _a = _a * x.value() % MOD;
    return *this;
  }
  constexpr modInt &operator/=(const modInt x) {
    assert(x.value() != 0);
    *this *= x.inverse();
    return *this;
  }
  constexpr modInt operator++() { return *this += modInt(1); }
  constexpr modInt operator--() { return *this -= modInt(1); }
};
template <u64 MOD>
constexpr modInt<MOD> operator+(const modInt<MOD> lha, const modInt<MOD> rha) {
  return modInt<MOD>(lha) += rha;
}
template <u64 MOD>
constexpr modInt<MOD> operator-(const modInt<MOD> lha, const modInt<MOD> rha) {
  return modInt<MOD>(lha) -= rha;
}
template <u64 MOD>
constexpr modInt<MOD> operator*(const modInt<MOD> lha, const modInt<MOD> rha) {
  return modInt<MOD>(lha) *= rha;
}
template <u64 MOD>
constexpr modInt<MOD> operator/(const modInt<MOD> lha, const modInt<MOD> rha) {
  return modInt<MOD>(lha) /= rha;
}
template <u64 MOD>
constexpr modInt<MOD> operator==(const modInt<MOD> lha, const modInt<MOD> rha) {
  return lha.value() == rha.value();
}
template <u64 MOD>
constexpr modInt<MOD> operator!=(const modInt<MOD> lha, const modInt<MOD> rha) {
  return !(lha.value() == rha.value());
}
template <u64 MOD>
std::ostream &operator<<(std::ostream &stream, const modInt<MOD> x) {
  stream << x.value();
  return stream;
}
template <u64 MOD>
std::istream &operator>>(std::istream &stream, modInt<MOD> &x) {
  u64 a;
  stream >> a;
  x = modInt<MOD>(a);
  return stream;
}
} // namespace mod
constexpr ll MOD = 1e9 + 7;
using modint = mod::modInt<MOD>;

char inverse(char c) { return 'R' + 'L' - c; }
int main() {
  int n;
  cin >> n;
  n = 2 * n;
  string s;
  cin >> s;
  if (s[0] == 'W' || s.back() == 'W') {
    cout << 0 << endl;
    return 0;
  }
  string which = string(n, ' ');
  which[0] = 'L';
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == s[i]) {
      which[i] = inverse(which[i - 1]);
    } else {
      which[i] = which[i - 1];
    }
  }
  int count_l = 0;
  for (int i = 0; i < n; i++)
    if (which[i] == 'L')
      count_l++;
  if (count_l != n / 2) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> conv_l(n), conv_r(n);
  conv_l[0] = 0;
  for (int i = 1; i < n; i++)
    conv_l[i] = conv_l[i - 1] + (which[i - 1] == 'L' ? 1 : 0);
  conv_r[0] = 0;
  for (int i = 1; i < n; i++)
    conv_r[i] = conv_r[i - 1] + (which[i - 1] == 'R' ? 1 : 0);
  modint ans = 1;
  for (int i = 0; i < n; i++)
    if (which[i] == 'R')
      ans *= conv_l[i] - conv_r[i];
  for (int i = 1; i <= n / 2; i++)
    ans *= i;
  cout << ans << endl;
}
