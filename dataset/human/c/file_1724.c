#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define MOD (ll)1000000007 //10^9 + 7
#define endl printf("\n")
typedef long long ll;

int
main(int argc, char *argv[])
{
  int n;
  int a[100], b[100], c[100];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n - 1; i++) scanf("%d", &c[i]);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += b[a[i] - 1];
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] + 1 == a[i + 1]) ans += c[a[i] - 1];
  }

  printf("%d\n", ans);

  return 0;
}
