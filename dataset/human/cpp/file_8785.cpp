#include <bits/stdc++.h>

template <typename InputIterator>
typename InputIterator::value_type
summation(InputIterator first, InputIterator last) {
  using T = typename InputIterator::value_type;
  T *p = new T();
  const auto sum = std::accumulate(first, last, *p);
  delete p;
  return sum;
}
template <typename T>
std::istream& operator>> (std::istream &stream, std::vector<T> &v);
template <typename T1, typename T2>
std::istream& operator>> (std::istream &stream, std::pair<T1, T2> &p);
template <typename T>
std::istream& operator>> (std::istream &stream, std::vector<T> &v) {
  for (auto &i : v) {
    stream >> i;
  }
  return stream;
}
template <typename T1, typename T2>
std::istream& operator>> (std::istream &stream, std::pair<T1, T2> &p) {
  stream >> p.first >> p.second;
  return stream;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n), b(m);
  std::cin >> a >> b;

  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= n - m; j++) {
      bool flag = true;
      for (int k = 0; k < m && flag; k++) {
        for (int l = 0; l < m && flag; l++) {
          if (a[i + k][j + l] != b[k][l]) {
            flag = false;
          }
        }
      }
      if (flag) {
        std::cout << "Yes" << std::endl;
        return 0;
      }
    }
  }
  std::cout << "No" << std::endl;
  return 0;
}
