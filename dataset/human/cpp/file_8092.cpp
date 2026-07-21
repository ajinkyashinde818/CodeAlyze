#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), s(n + 1);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) s[i + 1] = s[i] + a[i];

  ll ans = INFL;
  rep(i, 1, n) ans = min(ans, abs(s[i] - (s[n] - s[i])));
  cout << ans << endl;
  return 0;
}
