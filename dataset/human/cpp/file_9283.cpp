#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  char A[50][50];
  char B[50][50];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cin >> A[i][j];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++)
      cin >> B[i][j];
  }

  if (n < m) {
    cout << "No" << endl;
    return 0;
  }

  bool exist = false;

  for (int ly = 0; ly < n; ly++) {
    for (int lx = 0; lx < n; lx++) {
      if (ly + m - 1 >= n || lx + m - 1 >= n)
        continue;

      bool flag = true;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
          if (B[i][j] != A[i + ly][j + lx]) {
            flag = false;
          }
        }
      }
      if (flag)
        exist = true;
    }
  }

  cout << (exist ? "Yes" : "No") << endl;
}
