#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(n));
  vector<vector<char>> b(m, vector<char>(m));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      char num;
      cin >> num;
      a[i][j] = num;
    }
  }
  for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){
      char num;
      cin >> num;
      b[i][j] = num;
    }
  }
  
  bool foundBinA = false;
  for(int i=0; i<n-(m-1); i++){
    for(int j=0; j<n-(m-1); j++){
      bool isBsametoA = true;
      for(int k=0; k<m; k++){
        for(int l=0; l<m; l++){
          if(a[i+k][j+l] != b[k][l]){
            isBsametoA = false;
          }
        }
      }
      if(isBsametoA) foundBinA = true;
    }
  }
  if(foundBinA) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
