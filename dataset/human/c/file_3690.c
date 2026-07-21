#include <stdio.h>

int calcGCD(int a, int b) {
  int r = a % b;
  while (r) { a = b; b = r; r = a % b; }
  return b;
}

int main() {
  int a, b, g;
  scanf("%d %d", &a, &b);
  if (a < b) { g = calcGCD(b, a); } else { g = calcGCD(a, b); }
  printf("%ld\n", (long)a * b / g);
}
