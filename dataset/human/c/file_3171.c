#include <stdio.h>

// int a[200001]
int main() {
  int k, n;
  scanf("%d %d", &k, &n);

  int last;
  scanf("%d", &last);
  int first = last;
  int max = last;
  for (int i = 1; i < n + 1; i++) {
    int a;
    scanf("%d", &a);
    int d = (i == n) ? (k - a + first) : (a - last);
    max = d > max ? d : max;
    last = a;
  }
  printf("%d", k - max);
  return 0;
}
