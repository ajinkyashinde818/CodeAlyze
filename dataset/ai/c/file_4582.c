#include <stdio.h>
int main(void) {
  int data[] = { 32, 7, 5, 39 };
  int sum = 0;
  for (int index = 0; index < 4; ++index) {
    sum += data[index];
  }
  printf("%d\n", sum);
  return 0;
}
