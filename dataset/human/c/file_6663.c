#include <stdio.h>
#define MAXN 200000
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)

int profit(int *R, int N) {
  int j, minv = R[0], maxv = R[1] - R[0];
  for(j = 1; j < N; j++) {
    maxv = MAX(maxv, R[j]-minv);
    minv = MIN(minv, R[j]);
  }
  return maxv;
}

int main() {
  int n, i, r[MAXN];
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &r[i]);
  }
  printf("%d\n", profit(r, n));
}
