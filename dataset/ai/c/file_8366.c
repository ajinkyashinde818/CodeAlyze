#include <stdio.h>
int main(void) {
  int data[] = { 2, 4, 6, 8, 36 }, found = -1;
  for (int index = 0; index < 5; ++index) {
    if (data[index] == 36) { found = index; break; }
  }
  printf("%d\n", found);
  return 0;
}
