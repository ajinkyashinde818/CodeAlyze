#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int e[m];
  for (int i = 0; i < m; i++) {
    cin >> e[i];
  }
  bool used[n + 1];
  fill(used, used + n + 1, false);
  for (int i = m - 1; i >= 0; i--) {
    if (used[e[i]]) continue;
    cout << e[i] << endl;
    used[e[i]] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) cout << i << endl;
  }
  return 0;
}
