#include <stdio.h>
int main(void) {
  int count = 81;
  printf("%d %c\n", count, 'A' + count % 26);
  return 0;
}
