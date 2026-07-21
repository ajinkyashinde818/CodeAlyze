#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using ll = long long;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  bool flg = false;
  for(int i = 0; i <= n-m; i++) {
    for (int j = 0; j <= n-m; j++) {
      bool f = true;
      for (int k = 0; k < m; k++) {
        for (int l = 0; l < m; l++) {
          f &= a[i+k][j+l] == b[k][l];
        }
      }
      flg |= f;
    }
  }
  if (flg) cout << "Yes" << endl;
  else cout << "No" << endl;
}
