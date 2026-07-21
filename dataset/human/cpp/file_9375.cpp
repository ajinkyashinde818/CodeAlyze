#include <iostream>
#include <vector>
using namespace std;
int main () {
  int n,m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  for (int i = 0; i < m; i++) {
    cin >> b.at(i);
  }
  bool ans = false;
  for (int i = 0; i < n - m + 1; i++) {
    for(int j = 0; j < n - m + 1; j++) {
      for(int k = 0; k < m; k++) {
        bool next = false;
        for(int l = 0; l < m; l++) {
          if (a.at(i + k).at(j + l) != b.at(k).at(l)) {
            next = true;
            break;
          } else if (k == m - 1 && l == m - 1) {
            ans = true;
          }
        }
        if (next) {
          break;
        }
      }
    }
  }
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
