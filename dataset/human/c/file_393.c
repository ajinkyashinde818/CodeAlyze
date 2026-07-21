#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
  int n;
  int r;

  scanf("%d %d", &n, &r);

  if (n >= 10) {
    printf("%d\n", r);
    return (0);
  }

  printf("%d\n", r + 100 * (10 - n));
  return (0);
}
