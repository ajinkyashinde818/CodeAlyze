#include<stdio.h>

#define MAX 200000

int Max(int x, int y);
int Min(int x, int y);

int main(void) {
  long A[MAX];
  int n;
  long minv, maxv;
  scanf("%d", &n);

  for(int i=0; i<n; ++i) {
    scanf("%d", &A[i]);
  }

  minv = A[0];
  maxv = A[1] - A[0];
  for(int j=1; j<=n-1; ++j) {
    maxv = Max(maxv, A[j] - minv);
    minv = Min(minv, A[j]);
  }

  printf("%d\n", maxv);

  return 0;
}

int Max(int x, int y) {
  return x > y ? x : y;
}

int Min(int x, int y) {
  return x < y ? x : y;
}
