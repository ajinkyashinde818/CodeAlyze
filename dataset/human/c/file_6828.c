#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int main() {
  int n,a[300000],i;
  long long x=0;
  scanf("%d",&n);
  for (i=0;i<3*n;i++) {
    scanf("%d",&a[i]);
  }
  qsort(a, 3*n, sizeof(int), comp);
  for (i=n;i<3*n;i+=2) {
    x+=a[i];
  }
  printf("%lld\n",x);
  return 0;
}
