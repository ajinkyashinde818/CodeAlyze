#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define REP(i, n) for(int i = 0; i < n; i++)
#define INF 1000000000000 //10^12
#define MOD 1000000007 //10^9 + 7
typedef long long ll;

int dsc(const void *a, const void *b){
  ll A = *(ll *)a, B = *(ll *)b;
  if(A > B) return -1;
  if(A < B) return  1;
  return 0;
}

int
main(int argc, char *argv[])
{
  int n; ll a[300000];
  scanf("%d", &n);
  REP(i, 3 * n) scanf("%lld", &a[i]);

  qsort(a, 3 * n, sizeof(ll), dsc);

  int k = 0; ll ans = 0;
  while(k < n){
    ans += a[2 * k + 1];
    k++;
  }
  printf("%lld\n", ans);
  return 0;
}
