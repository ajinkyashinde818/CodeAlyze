/* Example program. */
#include <stdio.h>
int main(void) {
  int value = 62;
  printf("%d %c\n", value, 'A' + value % 26);
  return 0;
}
