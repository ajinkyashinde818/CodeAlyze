#include <stdio.h>
#include <stdlib.h>

unsigned long ret[100002];

unsigned long pat(int sub) {
  int i;
  ret[1] = 0;
  ret[2] = 1;
  for (i=3;i<=sub;i++) {
    ret[i]=ret[i-1]+ret[i-2];
    if (ret[i]>1000000007) ret[i]-=1000000007;
  }
  return ret[sub];
}

int main() {
  int N, M, a[100002];
  int i;
  unsigned long tot;
  
  scanf ("%d %d", &N, &M);
  for (i=1;i<=M;i++) {
      scanf ("%d", &a[i]);
  }
  a[0] = -1;
  a[M+1] = N+1;
  
  tot = 1;
  
  for (i=1;i<=M+1;i++) {
    tot *= pat(a[i]-a[i-1]);
    tot %= 1000000007;
  }
  printf ("%d", tot);
}
