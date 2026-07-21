#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 200000

int main() {
  int i, j;
  short int *x = (short int *)malloc(sizeof(short int) * N);
  short int *y = (short int *)malloc(sizeof(short int) * N);
  //int countx = 0, county = 0;
  int tempx, tempy;
  int flag = 0;

  for (i = 0; i < N;i++) {
    x[i] = 0;
    y[i] = 0;
  }
  int n, m;
  scanf("%d %d", &n, &m);

  for (i = 0; i < m;i++) {
    scanf("%d %d", &tempx, &tempy);
    if (tempx == 1) {
      x[tempy] = 1;
    }
    if (tempy == n) {
      y[tempx] = 1;
    }
  }

  for (i = 0; i < N;i++) {
    if (x[i] == 1) {
      if (y[i] == 1) {
        flag = 1;
        break;
      }
    }
  }
  
  if (flag == 1) {
    printf("POSSIBLE");
  }
  else {
    printf("IMPOSSIBLE");
  }

  return 0;
}
