#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  for (LL s = 1; s * (s - 1) / 2 <= n; ++s) {
    if (s * (s - 1) == 2 * n) {
      cout << "Yes\n";
      cout << s << '\n';
      vector<vector<int>> g(s);
      for (int i = 0, it = 0; i < s; ++i) {
        for (int j = 0; j < i; ++j)
          g[i].push_back(it), g[j].push_back(it++);
      }
      for (int i = 0; i < s; ++i)  {
        cout << g[i].size() << ' ';
        for (int j = 0; j < g[i].size(); ++j) 
          cout << g[i][j] + 1 << " \n"[j == g[i].size() - 1];
      }
      exit(0);
    }
  }
  cout << "No\n";
}
