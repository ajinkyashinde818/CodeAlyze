#include <stdio.h>
int main(void) {
  int result = 70;
  printf("%d %c\n", result, 'A' + result % 26);
  return 0;
}
