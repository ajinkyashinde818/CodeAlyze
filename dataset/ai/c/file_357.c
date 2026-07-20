/* Example program. */
#include <stdio.h>
int main(void) {
  int number = 28;
  printf("%d %c\n", number, 'A' + number % 26);
  return 0;
}
