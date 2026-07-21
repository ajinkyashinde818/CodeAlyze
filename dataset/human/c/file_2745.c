#include <stdio.h>

int main(void) {

  int x, y, z, k, s;
  int count = 0;
  scanf("%d%d", &k, &s);

  for (x = 0; x <= k; x++) {
    for (y = 0; y <= k; y++) {
      if ((s - (x + y)) >= 0 && (s - (x + y)) <= k)
         count++;
      }
    }

  printf("%d\n", count);

  return 0;
}
