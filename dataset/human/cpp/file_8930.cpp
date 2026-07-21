#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  
  vector<vector<int>> a(n), b(m);
  
  for ( int i = 0; i < n; i++ ){
    string s;
    cin >> s;
    for ( int j = 0; j < n; j++ )
      a[i].push_back(s[j] == '#' ? 1 : 0);
  }
  
  for ( int i = 0; i < m; i++ ){
    string s;
    cin >> s;
    for ( int j = 0; j < m; j++ )
      b[i].push_back(s[j] == '#' ? 1 : 0);
  }
    
  for ( int i = 0; i < n - m + 1; i++ ){
    for ( int j = 0; j < n - m + 1; j++ ){
      bool ok = true;
      for ( int k = 0; k < m; k++ ){
        for ( int l = 0; l < m; l++){
          if ( a[i+k][j+l] == b[k][l] ) continue;
          else{
            ok = false;
            break;
          }
        }
        if ( !ok ) break;
      }
      
      if ( ok ) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
