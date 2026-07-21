#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for (int i=0; i<n; i++)
    cin >> a.at(i);
  for (int i=0; i<m; i++)
    cin >> b.at(i);
  
  bool CAN = false;
  for (int i=0; i<n-m+1; i++) { //縦にずらす
    for (int j=0; j<n-m+1; j++) { //横にずらす
      bool can = true;
      for (int k=0; k<m; k++) { // 縦の探査
        for (int l=0; l<m; l++) { // 横の探査
          if (b.at(k).at(l) != a.at(i+k).at(j+l)) {
            can = false;
            break;
          }
        }
        if (!can) break;
      }
      if (can) {
        CAN = true;
        break;
      }
    }
    if (CAN) break;
  }
  if (CAN) cout << "Yes" << endl;
  else cout << "No" << endl;
}
