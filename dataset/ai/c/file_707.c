/* Example program. */
#include <stdio.h>
int main(void) {
  int result = 46;
  printf("%d %c\n", result, 'A' + result % 26);
  return 0;
}
