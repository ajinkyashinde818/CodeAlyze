#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<bool> > a(n, vector<bool>(n));
  vector<vector<bool> > b(m, vector<bool>(m));
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    for(int j = 0; j < n; j++){
      a[i][j] = (s[j] == '#' ? true : false);
    }
  }
  for(int i = 0; i < m; i++){
    string s;
    cin >> s;
    for(int j = 0; j < m; j++){
      b[i][j] = (s[j] == '#' ? true : false);
    }
  }

  for(int i = 0; i <= n - m; i++){
    for(int j = 0; j <= n - m; j++){
      bool match = true;
      for(int k = 0; k < m; k++){
        for(int l = 0; l < m; l++){
          if(a[i+k][j+l] != b[k][l]){
            match = false;
            k = m;
            l = m;
          }
        }
      }
      if(match){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
