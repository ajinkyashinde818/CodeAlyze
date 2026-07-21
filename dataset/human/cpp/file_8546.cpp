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

  bool include = false;
  for (int s = 0; s < n-m+1; s++) {
    for (int t = 0; t < n-m+1; t++) {
      bool flag = true;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
          if (a[s+i][t+j] != b[i][j]) {
            flag = false;
          }
        }
      }
      if (flag) include = true;
    }
  }

  cout << (include ? "Yes" : "No");
}
