#include<stdio.h>
#define MAX 200000

int main(){
  int n, i, R[MAX], maxv, minv;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
      scanf("%d", &R[i]);
  }

  maxv = -2000000000;
  minv = R[0];

  for (i=1; i<n; i++) {
      if (maxv < R[i]-minv) {
          maxv = R[i]-minv;
      }
      if (minv > R[i]) {
          minv = R[i];
      }
  }

  printf("%d\n", maxv);
  return 0;
}
