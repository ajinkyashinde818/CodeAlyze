#include <stdio.h>

int main(void) {
  int x[10000] = {1};
  int i = 0, j;

  do {
    scanf("%d",&x[i]);
    i++;
  } while (x[i - 1] != 0);

  for (j = 0; j < i - 1; j++)
    printf("Case %d: %d\n", j + 1, x[j]);
    return 0;
}
