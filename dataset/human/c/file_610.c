// Ver19.03
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF (1 << 29) * 2
#define LLINF 4545454545454545454
#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int upll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? -1 : *(ll *)a > *(ll *)b ? 1 : 0; }
int downll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? 1 : *(ll *)a > *(ll *)b ? -1 : 0; }
void sortup(ll *a, int n) { qsort(a, n, sizeof(ll), upll); }
void sortdown(ll *a, int n) { qsort(a, n, sizeof(ll), downll); }

char a[55][55], b[55][55];
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < m; i++)
  {
    scanf("%s", b[i]);
  }
  for (int i = 0; i <= n - m; i++)
  {
    for (int j = 0; j <= n - m; j++)
    {
      int flag = 1;
      for (int ii = 0; ii < m; ii++)
      {
        for (int jj = 0; jj < m; jj++)
        {
          if (a[i + ii][j + jj] != b[ii][jj])
          {
            flag = 0;
            break;
          }
        }
      }
      if (flag)
      {
        puts("Yes");
        return 0;
      }
    }
  }
  puts("No");
}
