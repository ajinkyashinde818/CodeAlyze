/* -------------------------------- Template -------------------------------- */

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <locale>
#include <iostream>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = std::min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = std::max(a, b); }

// template<typename T> constexpr T inf = [](){ assert(false); };
// template<> constexpr int inf<int> = 1e9;
// template<> constexpr ll inf<ll> = 1e18;
// template<> constexpr ld inf<ld> = 1e30;

struct yes_no : std::numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

void solve();

int main() {
  std::locale loc(std::locale(), new yes_no);
  std::cout << std::boolalpha << std::setprecision(12) << std::fixed;
  std::cout.imbue(loc);
  solve();
  return 0;
}

using namespace std;

/* -------------------------------- Library -------------------------------- */

/* ---------------------------------- Main ---------------------------------- */

using P = complex<ld>;

ld x[1024], y[1024], r[1024];
ld d[1024];
bool visited[1024];

void solve() {
  int N;
  cin >> x[0] >> y[0];
  cin >> x[1] >> y[1];
  cin >> N;
  REP(i,N) cin >> x[i+2] >> y[i+2] >> r[i+2];
  REP(i,1024) d[i] = 1e18;
  d[0] = 0;
  REP(i,N+2) {
    ld mi_d = 1e18;
    int p = -1;
    REP(j,N+2) {
      if (visited[j]) continue;
      if (d[j] < mi_d) { mi_d = d[j]; p = j; }
    }
    visited[p] = true;
    REP(j,N+2) {
      chmin(d[j], d[p] + max(0.0L, abs(P(x[p] - x[j], y[p] - y[j])) - r[p] - r[j]));
    }
  }
  cout << d[1] << endl;
  return;
}
