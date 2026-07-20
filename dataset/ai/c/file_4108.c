#include <stdio.h>
int main(void) {
  int data[] = { 56, 26, 7, 82 };
  int sum = 0;
  for (int index = 0; index < 4; ++index) {
    sum += data[index];
  }
  printf("%d\n", sum);
  return 0;
}
