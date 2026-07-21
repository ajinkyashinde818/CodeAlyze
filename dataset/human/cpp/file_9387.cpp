#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for(int i=0; i<n; i++){
    cin >> a.at(i);
  }
  for(int i=0; i<m; i++){
    cin >> b.at(i);
  }
  
  for(int i=0; i<n-m+1; i++){
    for(int j=0; j<n-m+1; j++){
      if (a.at(i).at(j) != b.at(0).at(0)) continue;
      bool c0 = true;
      int cnt = 0;
      for(int k1=0; k1<m; k1++){
        for(int k2=0; k2<m; k2++){
          if(a.at(i+k1).at(j+k2) != b.at(k1).at(k2)){
            c0=false;
            break;
          }
          cnt++;
        }
        if(c0 == false) break;
      }
      if (cnt == m * m) {
        cout << "Yes" << endl;
        return 0;
      }
    }

  }
  
  cout << "No" << endl;
  return 0;
}
