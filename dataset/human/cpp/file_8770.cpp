#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  bool flag = true;
  for (int i = 0; i < n - m + 1; i++) {
    for (int j = 0; j < n - m + 1; j++) {
      flag = true;
      for (int k = 0; k < m; k++) {
        for (int l = 0; l < m; l++) {
          if (a[k+i][l+j] != b[k][l]) {
            flag = false;
          }
        }
      }
      if (flag) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
