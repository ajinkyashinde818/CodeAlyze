#include <stdio.h>
#include <stdint.h>

int main(void) {
  int N;
  scanf("%d", &N);

  int minus = 0;
  int min = 1000000001;
  int64_t sum = 0;
  for(int i = 0; i < N; i++) {
    int64_t A;
    scanf("%ld", &A);
    int64_t B = (A < 0) ? -A : A; 
    sum += B;
    if(A < 0) minus++;
    if(B < min) min = B;
  }

  if(minus % 2) {
    sum -= min*2;
  }
  printf("%ld\n", sum);
  return 0;
}
