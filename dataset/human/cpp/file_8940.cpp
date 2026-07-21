#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define __DEBUG__ 1

typedef   signed long long int slli;
typedef unsigned long long int ulli;
const slli MAX_SLLI = 0x7FFFFFFFFFFFFFFF;
const slli MIN_SLLI = 0x8000000000000000;
const ulli MAX_ULLI = 0xFFFFFFFFFFFFFFFF;
const ulli MIN_ULLI = 0x0000000000000000;

#define N_TIMES(i, n)     for (ulli i = 0;     i <  n; ++i)
#define N_TIMES_REV(i, n) for (slli i = n - 1; i >= 0; --i)

#ifdef __DEBUG__
template<typename T>
std::ostream& operator<<(std::ostream &os, const std::list<T> &list)
{
  const std::string delim = ", ";
  typename std::list<T>::const_iterator itr = list.begin();
  while (itr != list.end()) {
    os << *itr;
    ++itr;
    if(itr != list.end()) os << delim;
  }
  return os;
}

template<typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &v)
{
  const std::string delim = ", ";
  for (unsigned n = 0; n < v.size(); ++n) {
    os << v[n];
    if((n + 1) < v.size()) os << delim;
  }
  return os;
}
#endif

bool match(
  const std::vector<std::string> &A,
  const std::vector<std::string> &B,
  unsigned p, unsigned q
)
{
  unsigned M = B.size();

  for (unsigned x = 0; x < M; ++x) {
    for (unsigned y = 0; y < M; ++y) {
      if (A[q + y][p + x] != B[y][x]) return false;
    }
  }

  return true;
}

bool match(
  const std::vector<std::string> &A,
  const std::vector<std::string> &B
)
{
  unsigned D = A.size() - B.size();

  for (unsigned x = 0; x <= D; ++x) {
    for (unsigned y = 0; y <= D; ++y) {
      if (match(A, B, x, y)) return true;
    }
  }
  
  return false;
}

int main()
{
  unsigned N, M;
  std::cin >> N >> M;

  std::vector<std::string> A(N), B(M);
  N_TIMES(n, N) std::cin >> A[n];
  N_TIMES(m, M) std::cin >> B[m];

  std::cout << (match(A, B) ? "Yes" : "No") << std::endl;

  return 0;
}
