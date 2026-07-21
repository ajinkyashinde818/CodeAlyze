#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  int a, b, k, ans[1000], i = 1, j = 0;

  if(scanf("%d %d %d", &a, &b, &k) == 1);

  while(i <= a) {

    if(a % i == 0 && b % i == 0) {
      ans[j] = i;
      j++;
    }
    i++;
  }

  printf("%d", ans[j - k]);

  return 0;
}
