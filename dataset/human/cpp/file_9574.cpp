#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string a[50];
  string b[50];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  bool ok = false;

  for (int sy = 0; sy < n; sy++) {
    if (sy + m > n) {
      break;
    }
    for (int sx = 0; sx < n; sx++) {
      if (sx + m > n) {
        break;
      }

      bool match = true;
      for (int y = 0; y < m; y++) {
        for (int x = 0; x < m; x++) {
          if (a[sy + y][sx + x] != b[y][x]) {
            match = false;
          }
        }
      }
      if (match) {
        ok = true;
      }
    }
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
