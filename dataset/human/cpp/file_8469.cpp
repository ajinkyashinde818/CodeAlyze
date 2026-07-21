#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long u64;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector< string > a, b;
  for (int i = 0; i < n; ++i) {
    string l;
    cin >> l;
    a.push_back(l);
  }
  for (int i = 0; i < m; ++i) {
    string l;
    cin >> l;
    b.push_back(l);
  }
  for (int i = 0; i <= n-m; ++i) {
    for (int j = 0; j <= n-m; ++j) {
      bool isin = true;
      for (int k = 0; k < m; ++k) {
        if (a[i+k].substr(j, m) != b[k]) {
          isin = false;
          break;
        }
      }
      if (isin) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
