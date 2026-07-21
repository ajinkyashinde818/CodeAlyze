#include <stdio.h>

int main(void) {

  long n,k;
  scanf("%ld %ld", &n, &k);
  long a[n];
  for (long i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
  }
  long ng = 0,ok = 1000000000,center,cut;
  while (ng+1 < ok) {
    center = (ng+ok)/2;
    cut = 0;
    for (long i = 0; i < n; i++) {
      cut += (a[i]+center-1)/center-1;
    }
    if (cut <= k) {
      ok = center;
    } else {
      ng = center;
    }
  }
  printf("%ld\n", ok);

  return 0;
}
