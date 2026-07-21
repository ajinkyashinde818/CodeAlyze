#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, b, res;

bool solve();

int main() {
  cin >> n;
  a.resize(n);
  for (auto &p : a) cin >> p;
  b.resize(n);
  for (auto &p : b) cin >> p;
  if (solve()) {
    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i) cout << res[i] << " \n"[i == n - 1];
  } else
    cout << "No" << endl;
  return 0;
}

bool solve() {
  vector<int> cnta(n + 1, 0), cntb(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    ++cnta[a[i]];
    ++cntb[b[i]];
  }
  for (int i = 1; i <= n; ++i) {
    if (cnta[i] + cntb[i] > n) return 0;
    cnta[i] += cnta[i - 1];
    cntb[i] += cntb[i - 1];
  }
  int dif = 0;
  for (int i = 1; i <= n; ++i) dif = max(dif, cnta[i] - cntb[i - 1]);
  res.resize(n);
  for (int i = 0; i < n; ++i) res[(i + dif) % n] = b[i];
  return 1;
}
