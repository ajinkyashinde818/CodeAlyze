#include <stdio.h>
void add_one(int *item) {
  ++*item;
}
int main(void) {
  int number = 55;
  add_one(&number);
  printf("%d\n", number);
  return 0;
}
