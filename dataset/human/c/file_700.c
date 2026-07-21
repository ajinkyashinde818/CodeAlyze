#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int i, j;
  int n, m;
  char **a, **b;
  int col;
  char *search;
  int flag;

  scanf("%d %d", &n, &m);

  a = (char**)malloc(sizeof(char*)*n);
  for (i = 0; i < n; i++) {
    a[i] = (char*)malloc(sizeof(char)*(n + 1));
    scanf("%s", a[i]);
  }
  b = (char**)malloc(sizeof(char*)*m);
  for (i = 0; i < m; i++) {
    b[i] = (char*)malloc(sizeof(char)*(m + 1));
    scanf("%s", b[i]);
  }

  flag = 0;
  for (i = 0; i < n; i++) {
    search = strstr(a[i], b[0]);
    if (search != NULL) {
      col = search - a[i];
      for (j = 1; j < m && i + j < n; j++) {
        search = strstr(a[i + j] + col, b[j]);
        if (search != a[i + j] + col)break;
      }
      if (j == m) {
        flag = 1;
        break;
      }
    }
  }

  printf(flag ? "Yes\n" : "No\n");

  for (i = 0; i < n; i++)free(a[i]);
  for (i = 0; i < m; i++)free(b[i]);
  free(a);
  free(b);
  return(0);
}
