#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int k = 1;
  while (k * (k + 1) < 2 * n) ++k;
  if (k * (k + 1) != 2 * n) {
    cout << "No\n";
    return 0;
  }
  ++k;
  vector<vector<int>> res(k);
  int cur = 1;
  for (int i = 0; i < k; ++i) {
    for (int j = i + 1; j < k; ++j) {
      res[i].push_back(cur);
      res[j].push_back(cur);
      ++cur;
    }
  }
  cout << "Yes\n";
  cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    cout << res[i].size();
    for (auto x : res[i]) cout << ' ' << x;
    cout << '\n';
  }
  return 0;
}
