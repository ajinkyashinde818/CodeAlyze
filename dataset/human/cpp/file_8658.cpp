#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  const int kMaxSize = 50;
  char a[kMaxSize][kMaxSize];
  char b[kMaxSize][kMaxSize];
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      cin >> a[y][x];
    }
  }
  for (int y = 0; y < m; ++y) {
    for (int x = 0; x < m; ++x) {
      cin >> b[y][x];
    }
  }
  bool exist = false;
  for (int ay = 0; ay < n; ++ay) {
    for (int ax = 0; ax < n; ++ax) {
      if (ay + m - 1 >= n || ax + m - 1 >= n) continue;
      bool match = true;
      for (int by = 0; by < m; ++by) {
        for (int bx = 0; bx < m; ++bx) {
          if (a[ay+by][ax+bx] != b[by][bx]) match = false;
        }
      }
      if (match) exist = true;
    }
  }
  cout << (exist ? "Yes" : "No") << endl;
}
