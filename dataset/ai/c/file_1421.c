/* Example program. */
#include <stdio.h>
int main(void) {
  int choice = 1;
  switch (choice) {
    case 0: puts("zero"); break;
    case 1: puts("one"); break;
    default: puts("other");
  }
  return 0;
}
