#include <stdio.h>

void Do(int N){
  int i, s;
  int A[N], B[N], C[N-1];
  for(i = 0;i < N;i++) scanf("%d", &A[i]);
  for(i = 0;i < N;i++) scanf("%d", &B[i]);
  for(i = 0;i < N - 1;i++) scanf("%d", &C[i]);
  s = 0;
  for(i = 0;i < N;i++){
    s += B[A[i]-1];
    if(A[i+1] == A[i] + 1) s += C[A[i]-1];
  }
  printf("%d\n", s);
}

int main(void){
  int N;
  scanf("%d", &N);
  Do(N);
  return 0;
}
