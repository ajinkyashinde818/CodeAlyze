#include <bits/stdc++.h>
using namespace std;
long long dp[3001][3];
int a[3];
int main () {
  int n;
  long long sum = 0;
  scanf ("%d %d %d %d",&a[0],&a[1],&a[2],&n);
  dp[0][0] = 1;
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x <= n-a[y]; x++) {
      for (int z = y; z >= 0; z--) {
        dp[x + a[y]][y] += dp[x][z];
      }
    }
    sum += dp[n][y];
  }
  printf ("%lld\n",sum);
  return 0;
}
