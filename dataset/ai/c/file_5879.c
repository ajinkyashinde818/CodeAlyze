#include <stdio.h>
void add_one(int *item) {
  ++*item;
}
int main(void) {
  int value = 46;
  add_one(&value);
  printf("%d\n", value);
  return 0;
}
