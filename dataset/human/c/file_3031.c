#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int main(void)
{
long K, N, A[200000], index, maxdiff;
char S[7];

  scanf("%ld %ld", &K, &N);
  maxdiff = 0;
  for (index = 0; index < N; ++index) {
    scanf("%ld", &A[index]);
    if (index > 0) {
      maxdiff = MAX(A[index]-A[index - 1], maxdiff);
    }
    if (index == N - 1) {
      maxdiff = MAX(K - A[index] + A[0], maxdiff);
    }
  }
  printf("%ld\n", K - maxdiff);
  
  return 0;
}
