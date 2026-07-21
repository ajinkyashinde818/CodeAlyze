#include<stdio.h>
#include<stdint.h>

int main(void) {
  int64_t x;
  scanf("%ld", &x);

  int64_t z = (x / 11) * 2;
  int64_t y = (x / 11) * 11;

  while(y < x) {
    y += (z % 2) ? 5 : 6;
    z++;
  }
  printf("%ld\n", z);
  return 0;
}
