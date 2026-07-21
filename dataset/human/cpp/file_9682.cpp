#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> image_a(n, string(""));
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    image_a[i] = str;
  }

  vector<string> image_b(m, string(""));
  for (int i = 0; i < m; i++) {
    string str;
    cin >> str;
    image_b[i] = str;
  }

  bool ans = false;
  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= n - m; j++) {
      bool is_include = true;
      for (int y = 0; y < m; y++) {
        for (int x = 0; x < m; x++) {
          if (image_b[y][x] != image_a[i + y][j + x]) {
            is_include = false;
          }
        }
      }
      if (is_include) {
        ans = true;
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

}
