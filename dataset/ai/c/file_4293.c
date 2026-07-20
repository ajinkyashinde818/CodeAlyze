#include <stdio.h>
int main(void) {
  int data[] = { 75, 8, 3, 83 };
  int sum = 0;
  for (int index = 0; index < 4; ++index) {
    sum += data[index];
  }
  printf("%d\n", sum);
  return 0;
}
