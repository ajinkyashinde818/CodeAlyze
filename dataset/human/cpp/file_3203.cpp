#include <bits/stdc++.h>

using namespace std;

long long dp[100001][2];
long long A[100001];

int main()
{
  int N;
  
  scanf("%d", &N);
  
  dp[0][1] = -1000000000000ll;
  for (int i = 1; i <= N; i++) {
    scanf("%lld", A + i);
    if (i == 1) continue;
    
    if (i == 2) {
      dp[i][0] = A[i] + A[i - 1];
      dp[i][1] = -dp[i][0];
    }
    else {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + A[i];
      dp[i][1] = max(-A[i] + -2 * A[i - 1] + dp[i - 1][0], -A[i] + 2 * A[i - 1] + dp[i - 1][1]);
    }
  }
  
  printf("%lld\n", max(dp[N][0], dp[N][1]));
  return 0;
}
