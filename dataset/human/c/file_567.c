#include <stdio.h>

int main(void) {
  int i, j, k, l, n, m;
  scanf("%d%d", &n, &m);
  char a[n][n + 10], b[m][m + 10];
  for(i = 0; i < n; ++i) scanf("%s", a[i]);
  for(i = 0; i < m; ++i) scanf("%s", b[i]);
  for(i = 0; i <= n - m; ++i) for(j = 0; j <= n - m; ++j) {
    bool s = true;
    for(k = 0; k < m; ++k) for(l = 0; l < m; ++l) if(a[i + k][j + l] != b[k][l]) s = false;
    if(s) {
      printf("Yes");
      return 0;
    }
  }
  printf("No");
  return 0;
}
