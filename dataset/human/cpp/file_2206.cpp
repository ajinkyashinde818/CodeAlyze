#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  int c = 0;
  for (int i = 0; i < n; ++i) c += a[i] < 0;
  lint res = 0;
  if (c & 1) {
    int mn = 2e9;
    for (int i = 0; i < n; ++i) mn = min(mn, abs(a[i]));
    for (int i = 0; i < n; ++i) res += abs(a[i]);
    res -= 2 * mn;
  } else {
    for (int i = 0; i < n; ++i) res += abs(a[i]);
  }
  cout << res << '\n';
}
