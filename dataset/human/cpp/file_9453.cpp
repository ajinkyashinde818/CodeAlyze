#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m;
  cin >> n >> m;
  
  vector<vector<char>> A(n, vector<char>(n));
  vector<vector<char>> B(m, vector<char>(m));
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A.at(i).at(j);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      cin >> B.at(i).at(j);
    }
  }
  
  bool ans = false;
  
  for (int i = 0; i < n-m+1; i++) {
    for (int j = 0; j < n-m+1; j++) {
      bool match = true;
      for (int y = 0; y < m; y++) {
        for (int x = 0; x < m; x++) {
          if(A.at(i+y).at(j+x) != B.at(y).at(x)){
            match = false;
          }
        }
      }
      if(match){
        ans = true;
      }
    }
  }
  
  if(ans){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }

 
}
