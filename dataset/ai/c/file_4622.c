#include <stdio.h>
int main(void) {
  int data[] = { 72, 18, 3, 90 };
  int sum = 0;
  for (int index = 0; index < 4; ++index) {
    sum += data[index];
  }
  printf("%d\n", sum);
  return 0;
}
