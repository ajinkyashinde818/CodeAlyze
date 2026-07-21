#include <stdio.h>

int main() {
  int n, day, x;
  int i;

  scanf("%d %d %d", &n, &day, &x);

  for (i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    x += ((day-1)/num + 1);
  }

  printf("%d\n", x);

  return 0;
}
