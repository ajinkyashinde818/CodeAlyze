#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


int main(){
  int n, m;
  cin >> n >> m;

  vector<vector<char>> N(n,vector<char>(n));
  vector<vector<char>> M(m,vector<char>(m));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> N[i][j];
    }
  }
  for(int i = 0; i < m; i++){
    for(int j = 0; j < m; j++){
      cin >> M[i][j];
    }
  }

  bool fin = true;
  for(int i = 0; i < (n - m + 1); i++){
    for(int j = 0; j < (n - m + 1); j++){
      bool f = false;
      for(int k = 0; k < m; k++){
        for(int l = 0; l < m; l++){
          if(N[k + i][l + j] != M[k][l]){
            f = true;
            break;
          }
          if(k == m - 1 && l == m - 1){
            fin = false;
            cout << "Yes" << endl;
          }
        }
        if(f){break;}
      }
      if(fin == false){
        break;
      }
    }
    if(fin == false){
        break;
      }
  }
  if(fin){cout << "No" << endl;}
}
