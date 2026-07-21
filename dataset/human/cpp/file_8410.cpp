#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> a, b;

bool solve();

int main() {
  cin >> n >> m;
  a.resize(n);
  for (auto& p : a) cin >> p;
  b.resize(m);
  for (auto& p : b) cin >> p;
  cout << (solve() ? "Yes" : "No") << endl;
  return 0;
}

bool solve() {
  for (int i = 0; i + m <= n; ++i)
    for (int j = 0; j + m <= n; ++j) {
      bool ch = 1;
      for (int k = 0; k < m; ++k)
        if (a[i + k].substr(j, m) != b[k]) ch = 0;
      if (ch) return 1;
    }
  return 0;
}
