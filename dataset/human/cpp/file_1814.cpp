#include <iostream>
#include <vector>
using namespace std;

bool used[200001];

int main(void) {
  int n, m; cin >> n >> m;
  vector<int> e(m, 0);
  for (int i = 0; i < m; i++) {
    cin >> e[i];
  }
  for (int i = m - 1; i >= 0; i--) {
    if (used[e[i]]) continue;
    cout << e[i] << endl;
    used[e[i]] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    cout << i << endl;
  }
  return 0;
}
