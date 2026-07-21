#include <bits/stdc++.h>

template <typename InputIterator>
typename InputIterator::value_type summation(InputIterator first,
                                             InputIterator last) {
  return std::accumulate(first, last, typename InputIterator::value_type());
}
template <typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &v);
template <typename T1, typename T2>
std::istream &operator>>(std::istream &stream, std::pair<T1, T2> &p);
template <typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &v) {
  for (auto &i : v) {
    stream >> i;
  }
  return stream;
}
template <typename T1, typename T2>
std::istream &operator>>(std::istream &stream, std::pair<T1, T2> &p) {
  stream >> p.first >> p.second;
  return stream;
}

int main() {
  constexpr int64_t mod = 1000000007;

  int64_t n;
  std::string s;
  std::cin >> n >> s;

  int64_t m = 0;
  int64_t ans = 1;

  for (const auto c : s) {
    if (m % 2 == 0) {
      if (c == 'W') {
        if (m == 0) {
          std::cout << 0 << std::endl;
          return 0;
        } else {
          ans *= m;
          ans %= mod;
          m--;
        }
      } else {
        m++;
      }
    } else {
      if (c == 'W') {
        m++;
      } else {
        if (m == 0) {
          std::cout << 0 << std::endl;
          return 0;
        } else {
          ans *= m;
          ans %= mod;
          m--;
        }
      }
    }
  }
  if (m != 0) {
    std::cout << 0 << std::endl;
  } else {
    for (int64_t i = 1; i <= n; i++) {
      ans *= i;
      ans %= mod;
    }
    std::cout << ans << std::endl;
  }

  return 0;
}
