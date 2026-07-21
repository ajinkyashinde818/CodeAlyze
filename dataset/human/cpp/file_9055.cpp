#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n,m;
  cin >> n >> m;
  
  vector<vector<char>> a(n,vector<char>(n)),b(m,vector<char>(m));
  
  for ( int i = 0; i < n; i++){
    for ( int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }
  
  for ( int i = 0; i < m; i++){
    for ( int j = 0; j < m; j++){
      cin >> b[i][j];
    }
  }
  
  int hantei = 1;
  
  for ( int s = 0; s <= n - m; s++){
    for ( int t = 0; t <= n - m; t++){
      for ( int i = 0; i < m; i++){
        for ( int j = 0; j < m; j++){
          if ( a[i+s][j+t] != b[i][j] ){
            hantei = 0;           
          }
        }
      }
      if ( hantei == 1 ){
        cout << "Yes" << endl;
        return 0;
      }else{
        hantei = 1;
      }
    }
  }
  
  cout << "No" << endl;  
  
}
