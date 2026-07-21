#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int h,w;
  scanf("%d %d", &h, &w);
  long a[h][w],b[h][w];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf("%ld", &a[i][j]);
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf("%ld", &b[i][j]);
    }
  }
  long ab[h][w];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      ab[i][j] = labs(a[i][j]-b[i][j]);
    }
  }
  long limit = (h+w)*80;
  long ***dp;
  dp = (long ***)malloc(sizeof (long**) * 80);
  for (long i = 0; i < 80; i++) {
  	dp[i] = (long **)malloc(sizeof (long*) * 80);
    for (long j = 0; j < 80; j++) {
      dp[i][j] = (long *)malloc(sizeof (long) * (limit+1));
      for (long k = 0; k <= limit; k++) {
        dp[i][j][k] = 0;
      }
    }
  }
  long value = ab[0][0];
  dp[0][0][value] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i != 0) {
        for (long k = 0; k <= limit; k++) {
          if (dp[i-1][j][k] == 1) {
            value = labs(k+ab[i][j]);
            dp[i][j][value] = 1;
            value = labs(k-ab[i][j]);
            dp[i][j][value] = 1;
          }
        }
      }
      if (j != 0) {
        for (long k = 0; k <= limit; k++) {
          if (dp[i][j-1][k] == 1) {
            value = labs(k+ab[i][j]);
            dp[i][j][value] = 1;
            value = labs(k-ab[i][j]);
            dp[i][j][value] = 1;
          }
        }
      }
    }
  }
  for (long i = 0; i <= limit; i++) {
    if (dp[h-1][w-1][i] == 1) {
      printf("%ld\n", i);
      break;
    }
  }

  return 0;
}
