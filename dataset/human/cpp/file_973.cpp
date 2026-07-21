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
  int64_t r, g, b, n;
  std::cin >> r >> g >> b >> n;
  int64_t c = 0;

  for (int64_t i = 0; i <= n / r; i++) {
    for (int64_t j = 0; j <= n / g; j++) {
      const auto le = n - i * r - j * g;
      if (0 <= le && le % b == 0) {
        c++;
      }
    }
  }
  std::cout << c << std::endl;
  return 0;
}
