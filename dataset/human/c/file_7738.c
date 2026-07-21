#include <stdio.h>

int main(void) {
  int n, k, p, i, j;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    scanf("%d%d", &k, &p);
    k %= p;
    if(k) printf("%d\n", k);
    else printf("%d\n", p);
  }
  return 0;
}
