#include <stdio.h>
void add_one(int *item) {
  ++*item;
}
int main(void) {
  int value = 69;
  add_one(&value);
  printf("%d\n", value);
  return 0;
}
