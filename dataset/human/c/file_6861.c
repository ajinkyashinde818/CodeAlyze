#include <stdio.h>

#define MAX_N   (100)
#define MIN_I   (-10000)

static int csmat[MAX_N + 1][MAX_N + 1];

int main() {
  int d, h, max_s, n, s, x, x0, y, y0;

  scanf("%d", &n);

  max_s = MIN_I * MAX_N * MAX_N;

  for (x = 0; x <= n; x++) csmat[0][x] = 0;

  for (y = 1; y <= n; y++) {
    h = 0;
    csmat[y][0] = 0;
    for (x = 1; x <= n; x++) {
      scanf("%d", &d);
      h += d;
      csmat[y][x] = h + csmat[y - 1][x];
      /*printf("(%d,%d)=%d\n", x, y, d);*/
    }

    for (x = 1; x <= n; x++) {
      for (y0 = 0; y0 < y; y0++) {
        for (x0 = 0; x0 < x; x0++) {
          s = csmat[y][x] - csmat[y][x0] - csmat[y0][x] + csmat[y0][x0];
          if (max_s < s) max_s = s;
        }
      }
    }
  }

  printf("%d\n", max_s);
  return 0;
}
