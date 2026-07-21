#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
  int N;
  int *A;
  int *a;
  int minabs = INFINITY;
  int minabs_pos;
  long long int sum = 0;
  int i;

  scanf("%d", &N);

  A = (int *)malloc(N * sizeof(int));
  a = A;

  for(i = 0; i < N; i++) {
    scanf("%d", a);
    a++;
    if(abs(A[i]) < minabs) {
      minabs = abs(A[i]);
      minabs_pos = i;
    }
  }

  for(i = 0; i < minabs_pos; i++) {
    if(A[i] < 0) {
      A[i] *= -1;
      A[i+1] *= -1;
    }
  }

  for(i = N - 1; i > minabs_pos; i--) {
    if(A[i] < 0) {
      A[i-1] *= -1;
      A[i] *= -1;
    }
  }

  for(i = 0; i < N; i++) {
    sum += A[i];
  }

  printf("%lld\n", sum);

  free(A);

  return 0;
}
