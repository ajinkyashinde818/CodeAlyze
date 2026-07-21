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
#define MAX 200001
#define MOD 1000000007
#define INF 1000000009
typedef long long int lli;

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  int s[MAX] = {0}, e[MAX] = {0};
  rep(i, 0, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    if ( a == 1 ) s[b] = 1;
    if ( b == n ) e[a] = 1;
  }
  rep(i, 2, n) {
    if ( s[i] && e[i] ) {
      printf("POSSIBLE\n");
      return 0;
    }
  }
  printf("IMPOSSIBLE\n");
  return 0;
}
