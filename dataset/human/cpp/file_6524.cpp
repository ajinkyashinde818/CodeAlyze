#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

const i64 mod = 1e9 + 7;
int n;
string s;
int main() {
  cin >> n >> s;

  i64 ans = 1, h = 0;
  for (char c : s) {
    if ((c == 'B' && h % 2 == 0) || (c == 'W' && h % 2 == 1)) {
      ++h;
    } else {
      (ans *= h) %= mod;
      --h;
    }
    if (h < 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  if (h != 0) ans = 0;

  for (i64 i = 1; i <= n; ++i) {
    (ans *= i) %= mod;
  }
  cout << ans << endl;
  return 0;
}
