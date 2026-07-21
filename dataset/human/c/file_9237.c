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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n, m) for (int i = (n), i < (m); i++)

ll gcd(ll a, ll b) {
  if (a == 0 || b == 0) return a + b;
  if (b > a) return gcd(b, a);
  return gcd(b, a % b);
}

char pp[1000000] = {};

int
main(int argc, char *argv[])
{
  int n, k, h, ans = 0;
  scanf("%d %d", &n, &k);
  rep(i, n) {
    scanf("%d", &h);
    if (h >= k) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
