#include <stdio.h>
int main(void) {
  int data[] = { 2, 4, 6, 8, 48 }, found = -1;
  for (int index = 0; index < 5; ++index) {
    if (data[index] == 48) { found = index; break; }
  }
  printf("%d\n", found);
  return 0;
}
