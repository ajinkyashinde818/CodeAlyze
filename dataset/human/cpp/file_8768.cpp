#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
using namespace std;

int n, m;
vector<string> a(60);
vector<string> b(60);

bool match(int x, int y) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (a[x + i][y + j] != b[i][j]) return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  bool found = false;
  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= n - m; j++) {
      if (match(i, j)) found = true;
    }
  }
  if (found)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
