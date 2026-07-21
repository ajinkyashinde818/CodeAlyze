#include<iostream>
#include<vector>
#include<queue>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const long MOD = 1e9 + 7;
int main()
{
  long n, m;
  cin >> n >> m ;


  vector<vector<char>> a(n, vector<char>(n) );
  vector<vector<char>> b(m, vector<char>(m) );

  for (int i = 0; i < n; ++i) {
    string c;
    cin >> c;
    for (int j = 0; j < c.size(); ++j) {
      a[i][j] = c[j];
      // cout << a[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    string c;
    cin >> c;
    for (int j = 0; j < c.size(); ++j) {
      b[i][j] = c[j];
    }
  }


  bool ans = false;
  for (int i = 0; i < n - m + 1; i++) {
    for (int j = 0; j < n - m + 1; j++) {
      bool isAlltrue = true;
      for (int k = 0; k < m; k++) {
        for (int l = 0; l < m; l++) {
          if (a[i + k][j + l] != b[k][l]){
            isAlltrue=false;
            break;
          }
        }
        if (!isAlltrue)break;
      }
      if (isAlltrue)ans = true;
      if (ans)break;
    }
    if (ans)break;
  }



  cout << (ans ? "Yes" : "No");


  return 0;
}
