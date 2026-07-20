#include <stdlib.h>
#include <stdio.h>
int main(void) {
  int *items = calloc(8, sizeof *items);
  if (items == NULL) return 1;
  items[0] = 44;
  printf("%d\n", items[0]);
  free(items);
  return 0;
}
