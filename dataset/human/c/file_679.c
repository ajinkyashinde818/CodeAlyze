#include <stdio.h>

int main(void){

  int n,m;
  scanf("%d %d", &n, &m);
  char a[n][n+1];
  char b[m][m+1];
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", b[i]);
  }

  int match = 0;
  int flag;
  for (int i = 0; i < n-m+1; i++) {
    for (int j = 0; j < n-m+1; j++) {
      flag = 0;
      for (int row = 0; row < m; row++) {
        for (int column = 0; column < m; column++) {
          if (a[i+row][j+column] != b[row][column]) {
            flag = 1;
            break;
          }
        }
        if (flag == 1) {
          break;
        }
      }
      if (flag == 0) {
        match = 1;
      }
      if (match == 1) {
        break;
      }
    }
    if (match == 1) {
      break;
    }
  }
  if (match == 1) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
