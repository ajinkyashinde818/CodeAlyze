#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
   int n, m;
   cin >> n >> m;
   vector<vector<char>> a(n, vector<char>(n)), b(m, vector<char>(m));
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
          cin >> a[i][j];
      }
   }
   for(int i = 0; i < m; i++) {
      for(int j = 0; j < m; j++) {
          cin >> b[i][j];
      }
   }

   bool flag = 0;
   for(int i = 0; i < n - m + 1; i++) {
      for(int j = 0; j < n - m + 1; j++) {
          flag = 1;
          for(int k = i; k < m + i; k++) {
              for(int l = j; l < m + j; l++) {
                  if(a[k][l] != b[k - i][l - j]) {
                      flag = 0;
                  }
              }
          }
          if(flag) {
              cout << "Yes" << endl;
              return 0;
          }
      }
   }
   cout << "No" << endl;

   return 0;
}
