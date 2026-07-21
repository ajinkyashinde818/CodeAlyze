#include <stdio.h>
#include <math.h>

int main(void){

  int n,m;
  long x;
  scanf("%d %d %ld", &n, &m, &x);
  long c[n],a[n][m];
  for (int i = 0; i < n; i++) {
    scanf("%ld", &c[i]);
    for (int j = 0; j < m; j++) {
      scanf("%ld", &a[i][j]);
    }
  }
  int bit[n];
  for (int i = 0; i < n; i++) {
    bit[i] = 0;
  }
  bit[0] = -1;
  long understand[m];
  int flag;
  long cost;
  long min = -1;
  for (int i = 0; i < pow(2,n); i++) {
    bit[0]++;
    for (int j = 1; j < n; j++) {
      bit[j] += bit[j-1]/2;
      bit[j-1] %= 2;
    }
    for (int j = 0; j < m; j++) {
      understand[j] = 0;
    }
    cost = 0;
    for (int j = 0; j < n; j++) {
      if (bit[j] == 1) {
        for (int k = 0; k < m; k++) {
          understand[k] += a[j][k];
        }
        cost += c[j];
      }
    }
    flag = 1;
    for (int j = 0; j < m; j++) {
      if (understand[j] < x) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      if (min == -1 || cost < min) {
        min = cost;
      }
    }
  }
  printf("%ld\n", min);

  return 0;
}
