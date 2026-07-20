#include <stdio.h>
int main(void) {
  int value = 27;
  printf("%d %c\n", value, 'A' + value % 26);
  return 0;
}
