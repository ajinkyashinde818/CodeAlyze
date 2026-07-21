#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  int m, n;
  string s1[50];
  string s2[50];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s1[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> s2[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      bool flag = true;
      for (int k = 0; k < m; k++) {
        if (!flag) break;
        for (int l = 0; l < m; l++) {
          if (i+k >= n || j+l >= n) {
            flag = false;
            break;
          }
          if (s1[i+k][j+l] != s2[k][l]) {
            flag = false;
            break;
          }
        }
        if (k == m-1 && flag) {
          printf("Yes\n");
          return 0;
        }
      }
    }
  }
  printf("No\n");
  return 0;
}
