#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  char a[100][100],b[100][100];
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      cin >> a[i][j];
  }
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < m; j++)
      cin >> b[i][j];
  }
    
  int x = 0, y = 0, r = 0;
  bool flag = 0;
  for(int i = 0; i < n; i++) {
    for(int j = r; j < n; j++) {
      if(a[i][j] == b[x][y]) {
        if(x == m-1 & y == m-1) {
          cout << "Yes" << endl;
          return 0;
        }
        else if(y == m-1) {
          flag = 1;
          break;
        }
        else {
          if(y == 0) r = j;
          y++;
        }
      }
      else {
        x = 0; y = 0; r = 0;
        flag = 0;
      }
    }
    y = 0;
    if(flag) x++;
    else x = 0; 
  }
  cout << "No" << endl;
}
