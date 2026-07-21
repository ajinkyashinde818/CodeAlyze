#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[100001];

int main() {
  int N,M, max, min, sumM, sumP;
  int i, j, k;
  scanf ("%d", &N);
  
  for (i=0;i<N;i++) {
      scanf("%d", &A[i]);
  }
  
  max = -10000;
  min = 10000;
  for (i=0;i<N;i++) {
    if (max<A[i]) {max=A[i]; j=i;}
    if (min>A[i]) {min=A[i]; k=i;}
  }
  if (j==k) k=1;
  
  sumP=0;
  sumM=0;
  for (i=0;i<N;i++) {
    if (i!=j && i!=k) {
      if (A[i]>0) sumP+=A[i];
      if (A[i]<0) sumM+=A[i];
    }
  }
  M = sumP-sumM+max-min;
  printf ("%d\n", M);
  
  for (i=0;i<N;i++) {
    if (i!=j && i!=k) {
      if (A[i]>0) {printf("%d %d\n", min, A[i]); min=min-A[i];}
      else        {printf("%d %d\n", max, A[i]); max=max-A[i];}
    }
  }
  printf("%d %d\n", max, min);
  
  return 0;
}
