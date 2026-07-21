#include <stdio.h>
#define DMAX 10
int main(void)
{
  int i, j, d, g, p[DMAX], c[DMAX], mpnum = 0;
  scanf("%d %d", &d, &g);
  for (i = 0; i < d; i++) {
    scanf("%d %d", &p[i], &c[i]);
    mpnum += p[i];
  }
  for (i = 0; i < 1 << d; i++) {
    int ans = 0, pnum = 0, mres = -1;
    for (j = 0; j < d; j++) {
      if ((i >> j) & 1) {
        ans += (j + 1) * 100 * p[j] + c[j];
        pnum += p[j];
      } else mres = j;
    }
    if (ans < g) {
      int rnum = (g - ans - 1) / (100 * (mres + 1))+ 1;
      if (rnum >= p[mres]) continue;
      pnum += rnum;
    }
    if (pnum < mpnum) mpnum = pnum;
  }
  printf("%d\n", mpnum);
}
