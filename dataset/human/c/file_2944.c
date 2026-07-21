#include <stdio.h>

int main() {
  int i, j, number_k, sum, count = 0;
  scanf("%d %d", &number_k, &sum);
  for(i = 0; i <= number_k; i++) {
    for(j = 0; j <= number_k; j++) {
      if(0 <= sum - (i + j) && sum - (i + j) <= number_k) {
        count++;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
