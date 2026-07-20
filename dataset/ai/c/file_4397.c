#include <stdio.h>
int main(void) {
  int data[] = { 13, 25, 9, 38 };
  int sum = 0;
  for (int index = 0; index < 4; ++index) {
    sum += data[index];
  }
  printf("%d\n", sum);
  return 0;
}
