#include <stdio.h>

void comp(int a, int b, int c, int d) {
  int ab = a * b, cd = c * d;
  if (ab > cd)
    printf("%d\n", ab);
  else
    printf("%d\n", cd);
}

int main(void) {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  comp(a, b, c, d);
  return 0;
}
