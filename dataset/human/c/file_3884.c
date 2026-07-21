#include <stdio.h>

int main() {
  int a, b, k;
  scanf("%d%d%d", &a, &b, &k);
  int max = a > b ? a : b;
  int count = 0;
  for (int i = max; i >= 1; i--) {
    if ((!(a % i)) && (!(b % i))) count++;
    if (count == k) {
      printf("%d", i);
      break;
    }
  }
  return 0;
}
