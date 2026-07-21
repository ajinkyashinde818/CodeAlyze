#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
  int n, m, signW, signH, tmpW, tmpH;
  cin >> n >> m;
  string a[n], b[m];
  string ans = "No";
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  int start = b[0][0];
  for (int i = 0; i < n - m + 1; i++) {
    for (int j = 0; j < n - m + 1; j++) {
      if (start == a[i][j]) {
        int tmpI = i;
        int cnt = 0;
        for (int k = 0; k < m; k++) {
          int tmpJ = j;
          if (cnt == 0 || cnt % m == 0) {
            for (int h = 0; h < m; h++) {
              if (a[tmpI][tmpJ] == b[k][h]) {
                cnt++;
                tmpJ++;
              }
              if (cnt == m * m) ans = "Yes";
            }
            tmpI++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}
