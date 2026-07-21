#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[20], B[20], C[20];

int main() {
  int N, result;
  int i;
  scanf ("%d", &N);
  
  for (i=0;i<N;i++) {
      scanf("%d", &A[i]);
  }
  for (i=0;i<N;i++) {
      scanf("%d", &B[i]);
  }
  for (i=0;i<N-1;i++) {
      scanf("%d", &C[i]);
  }
  
  result = 0;
  for (i=0;i<N;i++) {
  	result += B[i];
  	if ((i>0)&&(A[i]==A[i-1]+1)) result += C[A[i-1]-1];
  }
  
  
  printf("%d", result);
  return 0;
}
