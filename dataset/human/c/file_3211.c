#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;

int main(void) {
  int scan; // scanf result
  int answer; // stdout
  int k; // stdin
  int n;
  int *a;
  int distance;
  int max_diff;

  /* 標準出力からの読み込み */
  scan = scanf("%d", &k);
  scan = scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * (n + 1));
  for (int i = 0; i < n; i++) {
    scan = scanf("%d", &a[i]);
  }
  /* 最短移動距離の計算 */
  max_diff = 0;
  distance = a[n - 1] - a[0];
  if (distance <= (k / 2))
    answer = distance;
  else
  {
    for (int i = 0; i < (n - 1); i++) {
      if (max_diff < (a[i + 1] - a[i]))
        max_diff = a[i + 1] - a[i];
    }
    answer = k - max_diff;
    if (answer > distance)
      answer = distance;
  }

  printf("%d", answer);
  return (0);
}
