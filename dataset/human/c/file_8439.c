#include <stdio.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repi(i, n) for(int i = 1; i <= n; ++i)

int main(void) {
  int n, m, t;
  scanf("%d%d", &n, &m);
  int a[n];
  rep(i, n) scanf("%d", &a[i]);
  repi(i, m) {
    rep(j, n - 1) if(a[j] % i > a[j + 1] % i) t = a[j], a[j] = a[j + 1], a[j + 1] = t;
    /*rep(j, n) printf("%d ", a[j]);
    printf("\n");*/
  }
  rep(i, n) printf("%d\n", a[i]);
  return 0;
}
