#include <stdio.h>
#include <string.h>

#define MIN(A,B) (A)<(B)?(A):(B)
#define MAX(A,B) (A)>(B)?(A):(B)

#define N 5

int main(){
  int n, a, b, c=0, i, z;
  int A[100], B[100], C[100];

  scanf("%d", &n);
  for (i=1; i<=n; i++) scanf("%d", &A[i]);
  for (i=1; i<=n; i++) scanf("%d", &B[i]);
  for (i=1; i<=n-1; i++) scanf("%d", &C[i]);

  z=0;
  for (i=1; i<=n; i++){
    z+=B[A[i]];
    if (i>=2) {
      if (A[i]==A[i-1]+1) z+=C[A[i-1]];
    }
  }
  printf("%d\n", z);
  return 0;
}
