#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  
  vector<vector<char>> data(n, vector<char>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> data.at(i).at(j);
    }
  }
  
  vector<vector<char>> part(m, vector<char>(m));
  for(int i = 0; i < m; i++){
    for(int j = 0; j < m; j++){
      cin >> part.at(i).at(j);
    }
  }
  
  bool ok = false;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(j + m > n || i + m > n )
        continue;
      
      bool out = true;
      for(int a = 0; a < m; a++){
        for(int b = 0; b < m; b++){
          if(part.at(a).at(b) != data.at(i+a).at(j+b)){
            out = false;
          }
        }
      }
      if(out){
        ok = true;
      }
    }
  }
  
  if(ok)
    cout << "Yes" << endl;
 
  else
    cout << "No" << endl;            
}
