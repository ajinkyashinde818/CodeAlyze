#include <stdio.h>

int main(void) {
  int n, m, i;
  scanf("%d%d", &n, &m);
  if(n == 1) printf("%d\n", m);
  else if(n == 2) printf("0 %d\n", m);
  else {
    for(i = 0; i < n / 2 + 1; ++i) printf("0 ");
    for(; i < n; ++i) {
      if(i == n - 1) printf("%d\n", m);
      else printf("%d ", m);
    }
  }
  return 0;
}
