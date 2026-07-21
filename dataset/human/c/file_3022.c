#include <stdio.h>

int main(void)
{
  int K;
  int N;
  int A[200000];
  int i;
  int min = 10000000;
  int dist = 0;

  scanf("%d %d", &K, &N);
  for ( i = 0; i < N; i++ ) {
    scanf("%d", &A[i]);
  }

  // i番目からスタートする
  for ( i = 0; i < N; i++ ) {
    dist = 2*(A[i] - A[0]) + (A[N-1] - A[i]);
    if ( dist < min ) {
        min = dist;
    }
    if ( i > 0 ) {
      dist = (K - A[i]) + A[i - 1];
      if ( dist < min ) {
        min = dist;
      }
    }
  }
  for ( i = N - 1; i >= 0; i-- ) {
    dist = 2 * (A[N-1] - A[i]) + ( A[i] - A[0] );
    if ( dist < min ) {
      min = dist;
    }
    if ( i < (N - 1) ) {
      dist = A[i] + ( K - A[i+1] );
      if ( dist < min ) {
        min = dist;
      }
    }
  }

  printf("%d\n", min);

  return 0;

}
