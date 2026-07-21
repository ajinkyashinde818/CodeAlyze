#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>

static const int IINF = 1 << 30;
static const long long LINF = 1LL << 60;
static const long long MOD = 1.0e+9 + 7;

template <typename T> std::vector<T> vectors(std::size_t n, T val) {
  return std::vector<T>(n, val);
}

template <typename T, typename... Args>
auto vectors(std::size_t n, Args... args) {
  return std::vector<decltype(vectors<T>(args...))>(n, vectors<T>(args...));
}

template <class T> inline bool chmin(T &a, const T &b) {
  return (a > b) ? a = b, true : false;
}

template <class T> inline bool chmax(T &a, const T &b) {
  return (a < b) ? a = b, true : false;
}

template <class T> inline void chadd(T &a, const T &b) {
  a += b, a %= MOD;
  // TODO minus case
}

template <class T>
std::ostream &operator<<(std::ostream &s, const std::vector<T> &v) {
  if (v.empty())
    return s;
  s << *v.begin();
  for (auto iter = v.begin() + 1; iter != v.end(); ++iter)
    if (std::is_fundamental<T>::value)
      s << " " << *iter;
    else
      s << std::endl << *iter;
  return s;
}

int main() {
  // Input
  int R, G, B;
  int N;
  std::cin >> R >> G >> B >> N;

  // Main
  int res = 0;
  for (int r = 0; r <= N; ++r) {
    for (int g = 0; g <= N; ++g) {
      int rem = N - R * r - G * g;
      if (rem < 0)
        continue;
      if (rem % B == 0)
        res += 1;
    }
  }

  // Output
  std::cout << res << std::endl;

  return 0;
}
