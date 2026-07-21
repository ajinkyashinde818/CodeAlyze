#include <stdio.h>
#include <stdlib.h>

#define N 10

static int d[N][5];
static int n;

static
read()
{
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; ++i)
  for (j = 0; j < 5; ++j)
    scanf("%d", &d[i][j]);
  return n;
}

static
simulat(s)
int *s;
{
  int rval = 0;
  int i, j, k;
  for (i = 0; i < 5; ) {
    for (j = i + 1; j <= 5; ++j) {
      if (j < 5 && s[j] == s[i]) continue ;
      if (s[i] > 0 && j - i >= 3) {
        rval =+ s[i] * (j - i);
        for (k = i; k < j; ++k) {
          s[k] = -1;
        }
      }
      i = j;
      break ;
    }
  }
  return rval;
}

static void
compress()
{
  int i, j, k;
  for (i = 0; i < 5; ++i) {
    k = n - 1;
    for (j = k; j >= 0; --j) {
      if (d[j][i] < 0) continue ;
      d[k--][i] = d[j][i];
    }
    for (; k >= 0; --k) {
      d[k][i] = -1;
    }
  }
}

static
eval()
{
  int rval = 0;
  int i;
  for (;;) {
    const int rbak = rval;
    for (i = 0; i < n; ++i) {
      rval += simulat(d[i]);
    }
    if (rval == rbak) break ;
    compress();
  }
  return rval;
}

main()
{
  for (;;) {
    if (read() == 0) break ;
    printf("%d\n", eval());
  }
  return EXIT_SUCCESS;
}
