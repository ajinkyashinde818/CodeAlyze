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
#define MAX_N (1 << 17)

int
main(int argc, char *argv[])
{
  ll n;
  char s[200010];
  scanf("%lld", &n);
  scanf("%s", s);

  if (s[0] == 'W') printf("0\n");
  else {
    ll ans = 1;
    ll x = 0;
    ll i = 0;
    while (i < 2 * n) {
      if (i == 2 * n - 1) {
	if ((s[i] == 'B' && x % (ll)2 == 0) || (s[i] == 'W' && x % (ll)2 == 1) || x > 1) {
	  printf("0\n");
	  return 0;
	}
      }
      if (s[i] == 'W' && x == 0) {
	printf("0\n");
	return 0;
      }
      if ((s[i] == 'B' && x % (ll)2 == 0) || (s[i] == 'W' && x % (ll)2 == (ll)1)) {
	x++;
      } else if ((s[i] == 'B' && x % (ll)2 == (ll)1) || (s[i] == 'W' && x % (ll)2 == 0)) {
	ans *= x;
	ans %= MOD;
	x--;
      }
      i++;
    }
    ll z = 1;
    for (ll i = 0; i < n; i++) {
      z *= i + (ll)1;
      z %= MOD;
    }
    printf("%lld\n", (z * ans) % MOD);
  }

  return 0;
}
