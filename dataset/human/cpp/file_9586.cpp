#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(n));
  vector<vector<char>> b(m, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
    }
  }

  auto contains = [&](int x, int y) {
    for (int i = y; i < y + m; i++) {
      for (int j = x; j < x + m; j++) {
        if (a[i][j] != b[i-y][j-x])
          return false;
      }
    }
    return true;
  };

  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= n - m; j++) {
      if (contains(i, j)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;

  return 0;
}
