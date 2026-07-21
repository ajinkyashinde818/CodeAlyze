#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
int acs(const void *a, const void *b){return *(int*)a - *(int*)b;} /* 1,2,3,4.. */
int des(const void *a, const void *b){return *(int*)b - *(int*)a;} /* 8,7,6,5.. */
int cmp_char(const void *a, const void *b){return *(char*)a - *(char*)b;} /* a,b,c,d.. */
int cmp_str(const void *a, const void *b){return strcmp(*(const char **)a, *(const char **)b);} /* aaa,aab.. */
#define min(a,b) (a < b ? a: b)
#define max(a,b) (a > b ? a: b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MAX 100001
#define MOD 1000000007

typedef long long int lli;

int main(void) {
  lli n;
  scanf("%lld", &n);

  lli ans = 0;
  if (n % 2 == 0) {
    lli five  = 10;
    while (n / five != 0) {
      ans += n / five;
      five *= 5;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
