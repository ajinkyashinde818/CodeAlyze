#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  unsigned long K, N, A[200001];
  unsigned long i, max, tmp;
  
  scanf("%lu %lu", &K, &N);
  
  for (i = 0; i < N; i++) {
    scanf("%lu", &(A[i]));
  }
  A[N] = A[0] + K;
  
  max = 0;
  for (i = 0; i < N; i++) {
    if ((tmp = abs(A[i+1] - A[i])) > max) {
      max = tmp;
    }
  }
  
  printf("%lu", K-max);  

  return 0;
}
