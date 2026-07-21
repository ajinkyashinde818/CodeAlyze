#include <stdio.h>

int main() {

  int A, B, K, count = 0, i;
  if(A < B) {
    i = A;
    A = B;
    B = i;
  }
  scanf("%d %d %d", &A, &B, &K);
  for(i = B; i >= 1; i--) {
    if((A % i == 0) && (B % i == 0)) {
      count++;
    }
    if(count == K) {
      break;
    }
  }
  printf("%d\n", i);
  return 0;
}
