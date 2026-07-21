#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>  //for bool
#include <stdlib.h> // abs,labs,llabs
#include <limits.h>
#include <ctype.h>

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld; //%Lf

int main(void) {
  int n, flag = 0, ans = 0, i;
  scanf("%d", &n);
  int a[n + 1], b[n + 1], c[n];
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  for (i = 1; i < n; i++) {
    scanf("%d", &c[i]);
  }
  for (i = 1; i <= n; i++) {
    if (flag == 1) {
      ans += (b[a[i]] + c[a[i - 1]]);
      // printf("%d %d\n", b[a[i]] , c[a[i - 1]]);
      if((a[i + 1] == (a[i] + 1)) && i != n) {
        flag = 1;
      } else {
        flag = 0;
      }
    } else {
      ans += b[a[i]];
      // printf("%d\n", b[a[i]]);
      if((a[i + 1] == (a[i] + 1)) && i != n) {
        flag = 1;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
