/* Example program. */
#include <stdio.h>
int main(void) {
  int result = 72;
  printf("%d %c\n", result, 'A' + result % 26);
  return 0;
}
