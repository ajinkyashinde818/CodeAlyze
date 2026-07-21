#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  vector<vector<char>> a(n, vector<char>(n)), b(m, vector<char>(m));
  string s;
  int i, j, k, l;
  for(i = 0; i < n; i++){
    cin >> s;
    for(j = 0; j < n; j++){
      a.at(i).at(j) = s.at(j);
    }
  }
  for(i = 0; i < m; i++){
    cin >> s;
    for(j = 0; j < m; j++){
      b.at(i).at(j) = s.at(j);
    }
  }
  
  bool ans = true;
  for(i = 0; i <= n - m; i++){
    for(j = 0; j <= n - m; j++){
      ans = true;
      for(k = 0; k < m; k++){
        for(l = 0; l < m; l++){
          if(a.at(i + k).at(j + l) != b.at(k).at(l)){
            ans = false;
          }
        }
      }
      if(ans) break;
    }
    if(ans) break;
  }
  
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
