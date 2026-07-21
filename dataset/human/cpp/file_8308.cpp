#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n;
  char s[51];
  scanf("%d %d", &n, &m);
  vector<vector<int>> a(n, vector<int>(n)), b(m, vector<int>(m));
  for(int i = 0; i < n; i++) {
    scanf("%s", s);
    for(int j = 0; j < n; j++) a[i][j] = s[j];
  }
  for(int i = 0; i < m; i++) {
    scanf("%s", s);
    for(int j = 0; j < m; j++) b[i][j] = s[j];
  }
  for(int i = 0; i <= n - m; i++) {
    for(int j = 0; j <= n - m; j++) {
      int f = 1;
      for(int k = 0; k < m; k++)
        for(int l = 0; l < m; l++)
          if(a[i + k][j + l] != b[k][l]) f = 0;
      if(f) {
        printf("Yes\n");
        return 0;
      }
    }
  }
  printf("No\n");
}
