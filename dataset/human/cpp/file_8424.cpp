#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;

  char a[51][51], b[51][51];
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

  bool exist = false;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i + m - 1 >= n or j + m - 1 >= n) {
        continue;
      }

      bool match = true;
      for (int y = 0; y < m; y++) {
        for (int x = 0; x < m; x++) {
          if (a[i+y][j+x] != b[y][x]) {
            match = false;
          }
        }
      }
      if (match) {
        exist = true;
      }
    }
  }

  if (exist) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }


  return 0;
}
