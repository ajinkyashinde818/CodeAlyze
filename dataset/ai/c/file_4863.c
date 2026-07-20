#include <stdio.h>
int main(void) {
  int data[] = { 64, 27, 6, 91 };
  int sum = 0;
  for (int index = 0; index < 4; ++index) {
    sum += data[index];
  }
  printf("%d\n", sum);
  return 0;
}
