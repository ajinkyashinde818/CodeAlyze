#include<stdio.h>

#define N 200000
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
int main(){
  int n, i, minv, maxv;
  int A[N];
  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  
  maxv = -2000000000;
  minv = A[0];
  
  for (i= 1; i< n; i++){
    maxv = max(maxv, A[i]-minv);
    minv = min(minv, A[i]);
  }

  printf("%d\n",maxv);

  return 0;
}
