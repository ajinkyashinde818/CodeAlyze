#include <stdio.h>
#define L 57

int main(void) {
  int n, m;
  char a[L][L], b[L][L];

  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++)
    scanf("%s", a[i]);

  for (int i = 0; i < m; i++)
    scanf("%s", b[i]);

  for (int i = 0; i < n - m + 1; i++)
    for (int j = 0; j < n - m + 1; j++) {
      for (int k = 0; k < m; k++)
        for (int l = 0; l < m; l++)
          if (a[i+k][j+l]  != b[k][l])
            goto loopend;

      printf("Yes");
      return 0;

loopend:
      continue;
    }

  printf("No");
  
  return 0;
}
