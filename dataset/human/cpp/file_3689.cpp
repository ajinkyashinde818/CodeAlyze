#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define fst first
#define snd second

/* clang-format off */
template <class T, size_t D> struct _vec { using type = vector<typename _vec<T, D - 1>::type>; };
template <class T> struct _vec<T, 0> { using type = T; };
template <class T, size_t D> using vec = typename _vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
template <class T> inline void chmin(T &a, const T& b) { if (b < a) a = b; }
template <class T> inline void chmax(T &a, const T& b) { if (b > a) a = b; }
/* clang-format on */

const ll INF = 1ll << 60;

int main() {
#ifdef DEBUG
  ifstream cin("in.txt");
#endif
  int N;
  while (cin >> N) {
    vector<ll> A(N);
    for (ll& x : A) cin >> x;
    ll sum = 0, mn = INF;
    int neg = 0;
    for (ll x : A) {
      if (x < 0) ++neg;
      sum += abs(x);
      mn = min(mn, abs(x));
    }
    ll res;
    if (neg % 2 == 0) {
      res = sum;
    } else {
      res = sum - 2 * mn;
    }
    cout << res << endl;
  }
  return 0;
}
