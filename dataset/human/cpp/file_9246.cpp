#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

int main(){

  int n, m;
  cin >> n >> m;

  string a[n][n];
  string b[m][m];

  string tmp;
  for (int i = 0; i < n; i++){
    cin >> tmp;
    for (int j = 0; j < n; j++){
      a[i][j] = tmp[j];
    }
  }
  for (int i = 0; i < m; i++){
    cin >> tmp;
    for (int j = 0; j < m; j++){
      b[i][j] = tmp[j];
    }
  }

  // judge
  for (int i = 0; i <= n - m; i++){
    for (int j = 0; j <= n - m; j++){

      int flag = 0;
      for (int m1 = 0; m1 < m; m1++){
        for (int m2 = 0; m2 < m; m2++){

          if (a[i + m1][j + m2] == b[m1][m2]){
            flag += 1;
          }

        }
      }

      if (flag == m * m){
        cout << "Yes" << endl;
        return 0;
      }

    }
  }

  cout << "No" << endl;

  return 0;
}
