#include <stdio.h>
void add_one(int *item) {
  ++*item;
}
int main(void) {
  int value = 10;
  add_one(&value);
  printf("%d\n", value);
  return 0;
}
