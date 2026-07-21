#include <stdio.h>

int main(void) {

  int r,g,b,n;
  scanf("%d %d %d %d", &r, &g, &b, &n);
  long count = 0;
  int left;
  for (int i = 0; i*r <= n; i++) {
    for (int j = 0; i*r+j*g <= n; j++) {
      left = n-i*r-j*g;
      if (left%b == 0 && left/b >= 0) {
        count++;
      }
    }
  }
  printf("%ld\n", count);

  return 0;
}
