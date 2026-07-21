#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
  int n;
  cin >> n;
  int ans = -1;
  for (int i = 1; i * (i + 1) <= 2 * n; ++i) {
    if (i * (i + 1) == 2 * n)
      ans = i + 1;
  }
  if (ans == -1) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    cout << ans << endl;
    int k = 1;
    vector<vector<int>> v(ans);
    for (int i = 0; i < ans; ++i) {
      for (int j = i + 1; j < ans; ++j) {
        v[i].push_back(k);
        v[j].push_back(k);
        k++;
      }
    }
    for (int i = 0; i < ans; ++i) {
      cout << ans - 1 << " ";
      for (int j = 0; j < ans - 1; ++j) {
        cout << v[i][j];
        if (j < ans - 2) {
          cout << " ";
        }
      }
      cout << endl;
    }
  }
}
