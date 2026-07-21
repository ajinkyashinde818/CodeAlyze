#include <stdio.h>

#define MAX 200000

int max(int a,int b) { int v = a<b ? b : a; return v;}
int min(int a,int b) { int v = a<b ? a : b; return v;}

int main(void) {
  int R[MAX], n, i, maxv, minv;

  scanf("%d",&n);
  for (i=0;i<n;i++) scanf("%d",&R[i]);
  maxv = -2000000000;
  minv = R[0];

  for(i=1;i<n;i++) {
    maxv = max(maxv, R[i] - minv);
    minv = min(minv, R[i]);
  }
  printf("%d\n",maxv);

  return 0;
}
