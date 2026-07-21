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

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);

  int i,h,count = 0;
  for(i = 0; i<n; i++) {
    scanf("%d", &h);
    if (h >= k) count++;
  }
  printf("%d\n", count);
  return 0;
}
