#include <stdio.h>

int min(int a, int b) {
  return (a < b) ? a : b;
}

char S[1000001], *s;
int main(void) {
  int f[] = {0, 1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
  int a = 0, b = 1, tmp;
  int x;
  scanf("%s", &S);
  for (s = S; *s; ++s) {
    x = *s - 48;
    tmp = min(a + f[x], b + f[10 - x]);
    b = min(a + f[1 + x], b + f[9 - x]);
    a = tmp;
  }
  printf("%d\n", a);
  return 0;
}
