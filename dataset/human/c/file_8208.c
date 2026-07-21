#include <stdio.h> //printf()
#include <stdlib.h> //exit()

int main() {
	int A, B, C, D;
  if (scanf("%d %d %d %d", &A, &B, &C, &D) < 0) {
    exit(1);
  }
  int product_1 = A * B;
  int product_2 = C * D;
  if (product_1 >= product_2) {
    printf("%d\n", product_1);
  }else {
    printf("%d\n", product_2);
  }
  return 0;
}
