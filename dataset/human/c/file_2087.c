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
#define MAX 1000005
#define MOD 1000000007

typedef long long int lli;

int main(void) {
  char s[MAX];
  scanf("%s", s);
  int last = strlen(s) - 1;
  int cnt = 0;
  int add = 0;
  for ( int i = last; i >= 0; i-- ) {
    int n = (int)(s[i] - '0') + add;
    if ( (n <= 4) || (n == 5 && s[i - 1] < '5') ) {
      add = 0;
      cnt += n; 
      continue;
    }
    cnt += 10 - n;
    add = 1;
  }
  printf("%d\n", cnt + add);
  return 0;
}
