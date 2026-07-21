#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int acs(const void *a, const void *b) { 
  return *(int*)a - *(int*)b;
} /* 1,2,3,4.. */
int des(const void *a, const void *b) {
  return *(int*)b - *(int*)a;
} /* 8,7,6,5.. */
int cmp_char(const void *a, const void *b) { 
  return *(char*)a - *(char*)b;
} /* a,b,c,d.. */
int cmp_str(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
} /* aaa,aab.. */
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MAX 100005
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

int main(void) {
  char s[MAX];
  scanf("%s", s);
  int q;
  scanf("%d", &q);
  int t, f;
  char c;

  int si = strlen(s);

  char head[2*MAX] , rear[2*MAX];
  int hi = 2*MAX-1, ri = 0;
  int rev = 0;

  rep(i, 0, q) {
    scanf("%d", &t);
    if ( t == 1 ) rev = abs(rev-1);
    else {
      scanf("%d %c", &f, &c);
      if ( f == 1 ) {
        if ( rev ) { // 反転している
          rear[ri++] = c;
        } else {
          head[hi--] = c;
        }
      } else {
        if ( rev ) { // 反転している
          head[hi--] = c;
        } else {
          rear[ri++] = c;
        }
      }
    }
  }
  if ( rev ) {
    for ( int i = ri-1; i >= 0; i-- ) 
      printf("%c", rear[i]);
    for ( int i = si-1; i >= 0; i-- ) 
      printf("%c", s[i]);
    for ( int i = 2*MAX-1; i > hi; i-- ) 
      printf("%c", head[i]);
  } else {
    for ( int i = hi+1; i < 2*MAX; i++ ) 
      printf("%c", head[i]);
    for ( int i = 0; i < si; i++ ) 
      printf("%c", s[i]);
    for ( int i = 0; i < ri; i++ ) 
      printf("%c", rear[i]);
  }
  printf("\n");
  return 0;
}
