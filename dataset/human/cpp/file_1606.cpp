#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  int k = -1;
  for (int i = 2; i < n + 2; ++i) if (i * (i - 1) >> 1 == n) k = i;
  if (k == -1) return cout << "No" << '\n', 0;
  cout << "Yes" << '\n';
  cout << k << '\n';
  VV<> res(k);
  int p = 0, q = 1;
  for (int i = 0; i < n; ++i) {
    res[p].push_back(i + 1);
    res[q].push_back(i + 1);
    if (p == k - 2) break;
    if (q != k - 1) ++q;
    else ++p, q = p + 1;
  }
  for (int i = 0; i < k; ++i) {
    cout << k - 1 << ' ';
    for (int j = 0; j < k - 1; ++j) cout << res[i][j] << (j != k - 2 ? ' ' : '\n');
  }
}
