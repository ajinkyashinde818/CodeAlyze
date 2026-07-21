#include <stdio.h>
#include <math.h>

int main(){
  int i, n, maxv, minv, R[200000];

  scanf("%d", &n);
  for(i=0; scanf("%d", &R[i]) == 1; i++);

  maxv= R[1] -R[0];
  minv = R[0];
  for(i=1; i < n; i++){
    maxv = fmax(maxv, R[i]-minv);
    minv = fmin(minv, R[i]);
  }
  printf("%d\n", maxv);
  return 0;
}
