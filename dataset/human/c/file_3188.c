#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define INF 1000000
int main(){
  int unused __attribute__((unused));
  int K, N, i, max = 0;
  int *A;

  unused = scanf("%d %d", &K, &N);
  A = (int *)malloc(sizeof(int)*N);
  if(A==NULL) exit(0);
  for(i=0; i<N; i++) unused = scanf("%d", &A[i]);

  for(i=0; i<N-1; i++){
    if(max < abs(A[i+1] - A[i])) max = abs(A[i+1] - A[i]);
    //printf("max = %d\n", max);
  }
  if(max < abs(K - A[N-1]) + A[0]) max = abs(K - A[N-1]) + A[0];

  printf("%d", K-max);
  free(A);
  return 0;
}
