#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> as(n), bs(m);
  for (auto &v : as)
    cin >> v;
  for (auto &v : bs)
    cin >> v;

  bool flag = true;
  for (int i = 0; i <= n - m; ++i) {
    for (int j = 0; j <= n - m; ++j) {
      flag = true;
      for (int k = i; k < i + m; ++k) {
        for (int l = j; l < j + m; ++l) {
          if (as[k][l] != bs[k - i][l - j])
            flag = false;
        }
      }
      if (flag)
        break;
    }
    if (flag)
      break;
  }
  cout << (flag ? "Yes" : "No") << endl;
}
