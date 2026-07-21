#include <algorithm>
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
/* clang-format on */

int main() {
  ll N;
  while (cin >> N) {
    if (N == 1) {
      cout << "Yes" << endl;
      cout << 2 << endl;
      cout << 1 << " " << 1 << endl;
      cout << 1 << " " << 1 << endl;
      continue;
    }
    ll k = -1;
    for (ll i = 1; i <= N; i++) {
      if (i * (i - 1) / 2 == N) {
        k = i;
        break;
      }
    }
    if (k < 0) {
      cout << "No" << endl;
      continue;
    }
    vec<ll, 2> res(k);
    ll x = 1;
    for (int i = 0; i < k; i++) {
      for (int j = i + 1; j < k; j++) {
        res[i].push_back(x);
        res[j].push_back(x);
        ++x;
      }
    }
    cout << "Yes" << endl;
    cout << k << endl;
    for (int i = 0; i < k; i++) {
      cout << res[i].size();
      for (ll x : res[i]) cout << " " << x;
      cout << endl;
    }
  }
  return 0;
}
