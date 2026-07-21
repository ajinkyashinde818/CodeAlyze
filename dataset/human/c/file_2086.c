#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

static void reverse(char *s, size_t len) {
  for (int i = 0; i < len >> 1; i++) {
    int j = len - i - 1;
    char w = s[i];
    s[i] = s[j];
    s[j] = w;
  }
}

int main(int argc, char **argv) {
  char n[1000003];
  n[0] = '0';
  scanf("%s", n + 1);
  int m = strlen(n);
  reverse(n, m);
  int dp[m + 1][2];
  for (int i = 0; i < m + 1; i++) {
    dp[i][0] = 100000000;
    dp[i][1] = 100000000;
  }
  dp[0][0] = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      int d = n[i] - '0' + j;
      if (d < 10) {
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + d);
      }
      if (0 < d) {
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + 10 - d);
      }
    }
  }
  printf("%d\n", dp[m][0]);
  return EXIT_SUCCESS;
}
