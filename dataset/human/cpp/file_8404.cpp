#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;
  char a[n][n], b[m][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> b[i][j];
    }
  }

  bool imageFound;
  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= n - m; j++) {
      imageFound = true;
      for (int k = 0; k < m; k++) {
        for (int l = 0; l < m; l++) {
          if (a[i + k][j + l] != b[k][l]) {
            imageFound = false;
          }
        }
      }
      if (imageFound) {
        break;
      }
    }
    if (imageFound) {
        break;
      }
  }

  if (imageFound) {
    std::cout << "Yes" << "\n";
  } else {
    std::cout << "No" << "\n";
  }

  return 0;
}
