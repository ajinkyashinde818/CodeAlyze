#include <stdio.h>

int main() {
  int n;
  int min, maxDiff = (1 << (sizeof(int) * 8 - 2)) * -1;
  scanf(" %d", &n);
  int current, i;
  scanf(" %d", &min);
  for (i = 1; i < n; i++) {
    scanf(" %d", &current);
    int diff = current - min;
    if (diff > maxDiff) {
      maxDiff = diff;
    }
    if (current < min) {
      min = current;
    }
  }
  printf("%d\n", maxDiff);
}
