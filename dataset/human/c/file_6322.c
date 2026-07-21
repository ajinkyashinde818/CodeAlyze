#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define rep(i, n) for(int i = 0; i < (n); i++)
#define INF 1000000000000 //10^12
#define MOD 1000000007 //10^9 + 7
typedef long long ll;

int
main(int argc, char *argv[])
{
  int n, r[200000];
  scanf("%d", &n);
  rep(i, n) scanf("%d", &r[i]);

  int min[200000] = {};
  min[0] = 1000000000;
  int ans = -1000000000;
  for(int i = 1; i < n; i++){
    min[i] = Min(min[i - 1], r[i - 1]);
    ans = Max(ans, r[i] - min[i]);
  }
  printf("%d\n", ans);
  return 0;
}
