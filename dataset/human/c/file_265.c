#include<stdio.h>
#include<stdlib.h>

int comp(const void *a, const void *b){
  return *(int*)a - *(int*)b;
}

int main(){
  int N;
  scanf("%d", &N);
  int i, A[N], c = 0;
  long sum = 0;

  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
    if(A[i] < 0){
      c++;
      A[i] *= -1;
    }
    sum += A[i];
  }

  qsort(A, N, sizeof(int), comp);

  if(c % 2 == 1){
    sum -= 2 * A[0];
  }

  printf("%ld\n", sum);

  return 0;
}
