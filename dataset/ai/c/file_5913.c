#include <stdio.h>
void add_one(int *item) {
  ++*item;
}
int main(void) {
  int count = 80;
  add_one(&count);
  printf("%d\n", count);
  return 0;
}
