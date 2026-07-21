#include <stdio.h>

int main() {
  int a=0, b=0, k=0, count=0;
  scanf("%d %d %d", &a, &b, &k);
  for (int i=100; i>0; i--) {
    if (a%i == 0 && b%i == 0) {
      count++;
      if (count == k) {
        printf("%d\n", i);
        return 0;
      }
    }
  }
  printf("ans not found\n");
  return 0;
}
