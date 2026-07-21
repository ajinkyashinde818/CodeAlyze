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
  int h ,w;
  scanf("%d %d", &h, &w);
  char s[51][51];
  rep(i, 0, h) {
    scanf("%s", s[i]);
  }

  int mx[4] = {0, 1, 0, -1};
  int my[4] = {1, 0, -1, 0};
  int ok = 1;
  rep(hi, 0 ,h) {
    rep(wi, 0, w) {
      if (s[hi][wi] == '.') continue;
      int no = 1;
      rep(mi, 0, 4) {
        if (s[hi + my[mi]][wi + mx[mi]] == '.') continue; 
        no = 0; break;
      }
      if (no) { printf("No\n"); return 0; }
    }
  }
  printf("Yes\n");
  return 0;
}
