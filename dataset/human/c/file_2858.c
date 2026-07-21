#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  int k, s;
  int i, j;
  int count = 0;
  scanf("%d %d", &k, &s);

  for (i = 0; i <= k; i++) {
    for (j = 0; j <= k; j++) {
      if (s - i - j <= k && s-i-j >= 0) {
        count++;
      }
    }
  }

  printf("%d", count);

  return 0;
}
