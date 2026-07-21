#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> q(m);
  for (auto&& e : q) {
    cin >> e;
  }
  reverse(begin(q), end(q));
  vector<bool> used(n + 1);
  vector<int> res;
  for (int e : q) {
    if (used[e]) {
      continue;
    }
    used[e] = 1;
    res.push_back(e);
  }
  for (int i = 1; i <= n; ++i) {
    if (not used[i]) {
      res.push_back(i);
    }
  }
  for (int e : res) {
    cout << e << '\n';
  }
}
