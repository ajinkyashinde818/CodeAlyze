#include <iostream>
using namespace std;

int main(){
  int n, m, i, j;
  int flag = 0;
  char a[51][51], b[51][51];
  cin >> n >> m;
  for ( i = 0; i < n; i++ ){
    for ( j = 0; j < n; j++ ){
      cin >> a[i][j];
    }
  }
  for ( i = 0; i < m; i++ ){
    for ( j = 0; j < m; j++ ){
      cin >> b[i][j];
    }
  }
  
  for ( int shiftx = 0; shiftx <= n - m; shiftx++ ){
    for ( int shifty = 0; shifty <= n - m; shifty++ ){
      flag = 0;
      for ( i = 0; i < m; i++ ){
        for ( j = 0; j < m; j++ ){
          if ( a[i + shiftx][j + shifty] != b[i][j] ){
            flag = 1;
            break;
          }
        }
        if ( flag == 1 ) break;
      }
      if(flag == 0)break;
    }
    if(flag == 0)break;
  }
  
  if ( flag == 1 ){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}
