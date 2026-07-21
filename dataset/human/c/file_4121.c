#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int main() {
  int a,b,k;
  scanf("%d%d%d", &a, &b, &k);
  int x = gcd(a, b);
  int i;
  int cnt = 0;
  int *div = (int*)malloc(sizeof(int)*x);
  for (i = 1; i <= x; i++) {
    if (x % i == 0) {
      div[cnt++] = i;
    }
  }
  printf("%d\n", div[cnt - k]);
  return 0;
}
