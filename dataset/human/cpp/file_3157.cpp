#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

long long a[N];
long long dp[N][3];

void maximize(long long &x, long long y) {
  if (x < y) {
    x = y;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
  }
  dp[1][0] = a[0] + a[1];
  dp[1][1] = -(a[0] + a[1]);
  for (int i = 2; i < n; i++) {
    dp[i][0] = dp[i - 1][0] + a[i];
    maximize(dp[i][0], dp[i - 1][1] + a[i]);
    dp[i][1] = dp[i - 1][0] - a[i - 1] - a[i - 1] - a[i];
    maximize(dp[i][1], dp[i - 1][1] + a[i - 1] + a[i - 1] - a[i]);
  }
  printf("%lld\n", max(dp[n - 1][0], dp[n - 1][1]));
  return 0;
}
