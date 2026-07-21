#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

  int n,m;
  cin >> n >> m;

  vector<string> a(n);
  vector<string> b(m);

  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  for (int i = 0; i < m; i++) {
    cin >> b.at(i);
  }

  for (int k = 0; k < n - m + 1; k++) {

    for (int j = 0; j < n - m + 1; j++) {
      bool c = true;
      for (int i = 0; i < m; i++) {
        if (a.at(k+i).substr(j,m) != b.at(i)) {
          c = false;
          break;
        }
      }
      if (c) {
        std::cout << "Yes" << '\n';
        return 0;
      }

    }
  }

  std::cout << "No" << '\n';
  return 0;

}
