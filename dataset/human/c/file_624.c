#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int i, j, k;
  int n, m;
  int temp;
  char flag = 0;

  char a[52][55];
  char b[52][55];

  scanf("%d %d\n", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%[^\n]%*c", a[i]);
  }
  for (i = 1; i <= m; i++) {
    scanf("%[^\n]%*c", b[i]);
  }
  /*
    printf("\n");
    for (i = 0; i < n;i++) {
      printf("%s\n", a[i+1]);
    }
    printf("\n");
    for (i = 0; i < n;i++){
      printf("%s\n", b[i+1]);
    }
  */

  for (i = 1; i <= n - m + 1; i++) {
    for (k = 1; k <= n - m + 1; k++) {
      flag = 0;
      for (j = 1; j <= m; j++) {
        // if (j == i) {
        // temp = strstr(a[j + i - 1], b[j])-a[j+i-1];
        // printf("%p\n", strstr(a[j + i - 1], b[j])-a[j+i-1]);
        //} else {
        // printf("%p\n", strstr(a[j + i - 1], b[j])-a[j+i-1]);
        if (strstr(a[j + i - 1] + k - 1, b[j]) != a[j + i - 1] + k - 1) {
          flag = 1;
          break;
        }
      }
      //}

      if (flag == 0) {
        break;
      }
    }
    if (flag == 0) {
      break;
    }
  }

  if (flag == 0) {
    printf("Yes");
  } else {
    printf("No");
  }

  return 0;
}
