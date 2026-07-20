#include <stdio.h>
int main(void) {
  int data[] = { 2, 4, 6, 8, 81 }, found = -1;
  for (int index = 0; index < 5; ++index) {
    if (data[index] == 81) { found = index; break; }
  }
  printf("%d\n", found);
  return 0;
}
