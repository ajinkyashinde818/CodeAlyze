#include <bits/stdc++.h>
using namespace std;
int main() {

  int n,m;
  cin >> n >> m;
  vector<vector<char>> A(n,vector<char>(n));
  vector<vector<char>> B(m,vector<char>(m));
  
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> A.at(i).at(j);
    }
  }
  for (int i=0; i<m; i++) {
    for (int j=0; j<m; j++) {
      cin >> B.at(i).at(j);
    }
  }
  
  for (int i=0; i<=n-m; i++) {
    for (int j=0; j<=n-m; j++) {
      int count = 0;
      for (int k=0; k<m; k++) {
        for (int l=0; l<m; l++) {
          if (A.at(i+k).at(j+l) == B.at(k).at(l)) {
            count++;
            if (count >= m*m) {
              cout << "Yes" << endl;
              return 0;
            }
          }
        }
      }
    }
  }
  cout << "No" << endl;
}
