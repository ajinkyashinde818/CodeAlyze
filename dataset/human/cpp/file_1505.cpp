#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int w = 1;
  while (true) {
    if (w * (w + 1) == n * 2) {
      break;
    } else if (w * (w + 1) > n * 2) {
      cout << "No" << endl;
      return 0;
    }
    w++;
  }
  auto ans = vector<vector<int>>(w + 1);
  int s = 1;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < w - i; j++) {
      ans[i].push_back(s + j);
      ans[i + j + 1].push_back(s + j);
    }
    s += w - i;
  }
  cout << "Yes" << endl;
  cout << w + 1 << endl;
  for (int i = 0; i < w + 1; i++) {
    cout << w << "  ";
    for (int j = 0; j < w; j++) {
      if (j == w - 1) {
        cout << ans[i][j] << endl;
      } else {
        cout << ans[i][j] << "  ";
      }
    }
  }
  return 0;
}
