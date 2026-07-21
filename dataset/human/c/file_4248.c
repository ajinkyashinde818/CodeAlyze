#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
int acs(const void *a, const void *b) { return *(int *)a - *(int *)b; }                            /* 1,2,3,4.. */
int des(const void *a, const void *b) { return *(int *)b - *(int *)a; }                            /* 8,7,6,5.. */
int cmp_char(const void *a, const void *b) { return *(char *)a - *(char *)b; }                     /* a,b,c,d.. */
int cmp_str(const void *a, const void *b) { return strcmp(*(const char **)a, *(const char **)b); } /* aaa,aab.. */
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define mod 1000000007

int main(void)
{
  int n, m, broken[100001] = {0};
  scanf("%d %d", &n, &m);

  int bridge;
  int i;
  for (i = 0; i < m; i++)
  {
    scanf("%d", &bridge);
    broken[bridge] = 1;
  }

  int dp[100001] = {0};
  dp[0] = 1;
  for (i = 0; i < n; i++)
  {
    if (broken[i + 1] == 0)
      dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
    if (i + 2 <= n && broken[i + 2] == 0)
      dp[i + 2] = (dp[i + 2] + dp[i]) % mod;
  }

  printf("%d\n", dp[n]);

  return 0;
}
