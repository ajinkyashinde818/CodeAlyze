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
  int N;
  std::cin >> N;
  std::vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  // Main
  int numNegative = 0;
  long long minAbs = LINF;
  int minAbxIndex = -1;
  for (int i = 0; i < N; ++i) {
    if (A[i] < 0)
      ++numNegative;
    if (abs(A[i]) < minAbs) {
      minAbs = abs(A[i]);
      minAbxIndex = i;
    }
  }
  // std::cout << numNegative << std::endl;

  long long res = 0;
  if (numNegative % 2 == 0) {
    for (int i = 0; i < N; ++i) {
      res += abs(A[i]);
    }
  } else {
    for (int i = 0; i < N; ++i) {
      assert(minAbxIndex != -1);
      if (i == minAbxIndex)
        continue;
      res += abs(A[i]);
    }
    res -= abs(A[minAbxIndex]);
  }

  // Output
  std::cout << res << std::endl;

  return 0;
}
