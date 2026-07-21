#include <stdio.h>
#include <string.h>

int main(void)
{
  int n, m;
  int list[512][512], inv[512];
  int i, j;
  int a, b;
  int cnt;

  while (scanf("%d%d", &n, &m), n || m){
    memset(list, 0, sizeof(list));
    memset(inv, 0, sizeof(inv));
    for (i = 0; i < m; i++){
      scanf("%d%d", &a, &b);
      list[a][b] = list[b][a] = 1;
    }
    for (i = 2; i <= n; i++){
      if (list[1][i]){
        inv[i] = 1;
        for (j = 2; j <= n; j++){
          if(list[i][j]){
            inv[j] = 1;
          }
        }
      }
    }
    cnt = 0;
    for (i = 2; i <= n; i++){
      if (inv[i]){
        cnt++;
      }
    }
    printf("%d\n", cnt);
  }

  return (0);
}
