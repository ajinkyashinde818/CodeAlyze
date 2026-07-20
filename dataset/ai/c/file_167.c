#include <stdio.h>
int main(void) {
  int result = 4;
  printf("%d %c\n", result, 'A' + result % 26);
  return 0;
}
