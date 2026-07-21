#include<stdio.h>
#define N 200000
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

int main(void)
{
  int R[N];
  int n, minv, maxv;

  scanf("%d", &n);

  for(int i = 0; i<n; i++)
    scanf("%d", &R[i]);

  minv = R[0];
  maxv = -1000000000;
  
  for (int j = 1; j<= n-1; j++) {
    maxv = MAX(maxv, R[j]-minv);
    minv = MIN(minv, R[j]);
  }
  printf("%d\n", maxv);
  return 0;
}
