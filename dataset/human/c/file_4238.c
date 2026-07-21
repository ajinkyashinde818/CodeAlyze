#include<stdio.h>
#include<stdlib.h>

#define MOD 1000000007

int main(void) {
  int i, j, n, m, t;
  int *brk;
  int *d;

  scanf("%d", &n);
  d = malloc(sizeof(int) * (n + 1));
  for (i = 0; i < n; i++) d[i] = 0;

  scanf("%d", &m);
  brk = malloc(sizeof(int) * m);

  for (i = 0; i < m; i++) {
    scanf("%d", &t);
    d[t] = - 1;
  }

  d[0] = 1;
  for (i = 1; i <= n; i++) {
    if (d[i] < 0) {
      d[i] = 0;
      continue;
    }
    d[i] += d[i - 1];
    d[i] %= MOD;
    if (i >= 2) {
      d[i] += d[i - 2];
      d[i] %= MOD;
    } 
  }

  printf("%d\n", d[n]);
}
