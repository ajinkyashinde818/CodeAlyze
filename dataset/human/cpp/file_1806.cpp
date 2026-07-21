#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (int i = 0; i < m; i++)
    cin >> v[i];
  reverse(v.begin(), v.end());
  vector<bool> used(n);
  vector<int> ans;
  for (int i = 0; i < m; i++) {
    if (!used[v[i] - 1]) {
      ans.push_back(v[i]);
    }
    used[v[i] - 1] = true;
  }
  for (int i = 0; i < n; i++)
    if (!used[i])
      ans.push_back(i + 1);
  for (auto &i : ans)
    cout << i << endl;
  return 0;
}
