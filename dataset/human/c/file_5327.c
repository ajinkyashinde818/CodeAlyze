#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(x, y) (((x) > (y)) ? (y) : (x))
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
#define ADDIF(ii) do { \
    if (i##ii) { \
      cc += c[ii]; \
      for (int j = 0; j < m; j++) { \
        aa[j] += a[ii][j]; \
      } \
    } \
} while(0);
int main()
{
  int n, m, x;
  int c[12];
  int a[12][12];
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &c[i]);
    for (int j = 0; j < m; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
  int minc = 100000000;
  for (int i0 = 0; i0 < 2 - (n - 0 <= 0); i0++)
  for (int i1 = 0; i1 < 2 - (n - 1 <= 0); i1++)
  for (int i2 = 0; i2 < 2 - (n - 2 <= 0); i2++)
  for (int i3 = 0; i3 < 2 - (n - 3 <= 0); i3++)
  for (int i4 = 0; i4 < 2 - (n - 4 <= 0); i4++)
  for (int i5 = 0; i5 < 2 - (n - 5 <= 0); i5++)
  for (int i6 = 0; i6 < 2 - (n - 6 <= 0); i6++)
  for (int i7 = 0; i7 < 2 - (n - 7 <= 0); i7++)
  for (int i8 = 0; i8 < 2 - (n - 8 <= 0); i8++)
  for (int i9 = 0; i9 < 2 - (n - 9 <= 0); i9++)
  for (int i10 = 0; i10 < 2 - (n - 10 <= 0); i10++)
  for (int i11 = 0; i11 < 2 - (n - 11 <= 0); i11++) {
    int cc = 0;
    int aa[12] = {0};
    ADDIF(0);
    ADDIF(1);
    ADDIF(2);
    ADDIF(3);
    ADDIF(4);
    ADDIF(5);
    ADDIF(6);
    ADDIF(7);
    ADDIF(8);
    ADDIF(9);
    ADDIF(10);
    ADDIF(11);
    int pass = 1;
    for (int j = 0; j < m; j++) {
      if (aa[j] < x) {
        pass = 0;
        break;
      }
    }
    if (!pass) {
      continue;
    }
    minc = MIN(minc, cc);
  }
  if (minc == 100000000) {
    printf("-1");
  } else {
    printf("%d", minc);
  }
  return 0;
}
