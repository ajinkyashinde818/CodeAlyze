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
#define rep(i, n) for (int i = 0; i < n; i++)
#define MAX 100001
#define MOD 1000000007

typedef long long int lli;

int main(void)
{
  int n, a[MAX];

  scanf("%d", &n);
  rep(i, n)
  {
    scanf("%d", &a[i + 1]);
  }

  long long int dp[MAX][2];
  dp[1][0] = a[1];
  dp[1][1] = -a[1];
  for (int i = 2; i <= n; i++)
  {
    dp[i][0] = max(dp[i - 1][0] + a[i], dp[i - 1][1] - a[i]);
    dp[i][1] = max(dp[i - 1][0] - a[i], dp[i - 1][1] + a[i]);
  }

  printf("%lld\n", dp[n][0]);
  return 0;
}
